from models import Hub, Connection, MapData



class ParseError(Exception):
    """Error de sintaxis o de reglas del archivo."""


def parse_metadata(tokens: list[str], line_number: int) -> dict[str, str]:
    """Convierte '[key=value key=value]' en un diccionario."""
    if not tokens:
        return {}

    metadata_text = " ".join(tokens)

    if not metadata_text.startswith("[") or not metadata_text.endswith("]"):
        raise ParseError(
            f"Line {line_number}: metadata must use brackets"
        )

    content = metadata_text[1: -1].strip()

    if not content:
        return {}

    metadata: dict[str, str] = {}

    for pair in content.split():
        if "=" not in pair:
            raise ParseError(
                f"Line {line_number}: invalid metadata '{pair}'"    
            )

        key, value = pair.split("=", maxsplit=1)

        if not key or not value:
            raise ParseError(
                f"Line {line_number}: invalud metadata '{pair}'"
            )

        if key in metadata:
            raise ParseError(
                f"Line {line_number}: duplicate metadata '{key}'"
            )

        metadata[key] = value

    return metadata


def parse_hub(parts: list[str], line_number: int) -> Hub:
    """Convierte una linea de hub en un objeto Hub validado."""
    if len(parts) < 4:
        raise ParseError(f"Line {line_number}: incomplete hub definition")

    metadata = parse_metadata(parts[4:], line_number)

    valid_keys = {"color", "zone", "max_drones"}
    invalid_keys = set(metadata) - valid_keys

    if invalid_keys:
        invalid_key = invalid_keys.pop()
        raise parseError(
            f"Line {line_number}: unknown metadata '{invalid_key}'"
        )


    raw_data: dict[str, object] = {
        "name": parts[1],
        "x": parts[2],
        "y": parts[3],
        "color": metadata.get("color"),
        "zone_type": metadata.get("zone", "normal"),
        "max_drones": metadata.get("max_drones", 1),
    }

    try:
        return Hub.model_validate(raw_data)
    except ValueError as error:
        raise ParseError(f"Line {line_number}: {error}") from error




def parse_drone_count(parts: list[str], line_number: int) -> int:
    """Valida la linea nbdrones."""
    if len(parts) != 2:
        raise ParseError(
            f"Line {line_number}: expected 'nbdrones <positive integer>'"
        )

    try:
        drone_count = int(parts[1])
    except ValueError as error:
        raise ParseError(
            f"Line {line_number}: drone count must be an integer"
        ) from error

    if drone_count <= 0:
        raise ParseError(
            f"Line {line_number}: drone count must be positive"
        )

    return drone_count


def parse_connection(
        parts: list [str],
        line_number: int,
        hubs: dict[str, Hub],
        seen_connections: set[tuple[str, str]],
    ) -> Connection:
    """Convierte y valida una linea connection."""
    if len(parts) < 2:
        raise ParseError(
            f"Line {line_number}: incomplete connection definition"
        )

    try:
        source, target = parts[1].split("-", maxsplit=1)
    except ValueError as error:
        raise ParseError(
            f"Line {line_number}: invalid connection syntax"
        ) from error

    if not source or not target:
        raise ParseError(
            f"Line {line_number}: connection requieres two hub names"
        )

    if source not in hubs or target not in hubs:
        raise ParseError(
            f"Line {line_number}: connection references unknown hub"
        )

    metadata = parse_metadata(parts[2:], line_number)
    
    valid_keys = {"max_link_capacity"}
    invalid_keys = set(metadata) - valid_keys

    if invalid_keys:
        invalid_key = invalid_keys.pop()
        raise ParseError(
            f"Line {line_number}: unknown metadata '{invalid_key}'"
        )

    raw_data: dict[str, object] = {
        "source": source,
        "target": target,
        "max_link_capacity": metadata.get("max_link_capacity", 1),
    }

    try:
        connection = Connection.model_validate(raw_data)
    except ValueError as error:
        raise ParseError(f"Line {line_number}: {error}") from error

    if connection.key in seen_connections:
        raise ParseError(
            f"Line {line_number}: duplicate connection '{parts[1]}'"
        )

    seen_connections.add(connection.key)
    return connection


def parse_file(path: str) -> MapData:
    drone_count: int | None = None
    hubs: dict[str, Hub] = {}
    connections: list[Connection] = []
    seen_connections: set[tuple[str, str]] = set()

    start_hub: Hub | None = None
    end_hub: Hub | None = None

    with open(path, encoding="utf-8") as file:
        for line_number, raw_line in enumerate(file, start=1):
            line = raw_line.strip()

            if not line or line.startswith("#"):
                continue

            parts = line.split()
            command = parts[0]

            if command == "nb_drones:":
                drone_count = parse_drone_count(parts, line_number)

            elif command in {"start_hub:", "end_hub:", "hub:"}:
                hub = parse_hub(parts, line_number)

                if hub.name in hubs:
                    raise ParseError(
                        f"Line {line_number}: duplicate hub '{hub.name}'"
                    )

                if command == "start_hub:":
                    if start_hub is not None:
                        raise ParseError(
                            f"Line {line_number}: multiple start hubs"
                        )
                    start_hub = hub

                elif command == "end_hub:":
                    if end_hub is not None:
                        raise ParseError(
                            f"Line {line_number}: multiple end hubs"
                        )
                    end_hub = hub

                hubs[hub.name] = hub

            elif command == "connection:":
                connection = parse_connection(
                    parts,
                    line_number,
                    hubs,
                    seen_connections,
                )
                connections.append(connection)

            else:
                raise ParseError(
                    f"Line {line_number}: unknown command '{command}'"
                )

    if start_hub is None:
        raise ParseError("Missing start hub")

    if end_hub is None:
        raise ParseError("Missing end hub")

    if drone_count is None:
        raise ParseError("Missing nb_drones declaration")

    return MapData(
        drone_count=drone_count,
        hubs=hubs,
        connections=connections,
        start_hub=start_hub.name,
        end_hub=end_hub.name,
    )
