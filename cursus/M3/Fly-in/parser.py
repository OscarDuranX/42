"""Parser del formato de mapas de Fly-in.

Estructura (SOLID):
- MetadataParser: convierte '[k=v ...]' en diccionario.
- LineHandler (y subclases): traduce UNA clase de linea a objetos.
- MapBuilder: acumula el estado y aplica las reglas del mapa.
- MapParser: lee lieas y las reparte al handler correcto.
"""

from abc import ABC, abstractmethod
from collections.abc import Iterable
from enum import Enum
from typing import TypeVar

from pydantic import BaseModel, ValidationError

from errors import ParseError
from models import Connection, FleetConfig, Hub, MapData

DRONE_COUNT_KEYWORD = "nb_drones:"

M = TypeVar("M", bound=BaseModel)


def describe_validation_error(error: ValidationError) -> str:
    """Convierte un ValidationError de Pydantic en una frase corta."""
    problems: list[str] = []
    for item in error.errors():
        where = ".".join(str(part) for part in item["loc"])
        message = item["msg"].removeprefix("Value error, ")
        problems.append(f"{where}: {message}" if where else message)
    return "; ".join(problems)


class HubRole(Enum):
    """Papel de un hub dentro del mapa."""

    REGULAR = "regular"
    START = "start"
    END = "end"


class MetadataParser:
    """Convierte el bloque '[key=value key=value]' en un diccionario."""

    def parse(self, tokens: list[str], line_number: int) -> dict[str, str]:
        """Parsea los tokens de metadata de una linea."""
        if not tokens:
            return {}

        text = " ".join(tokens)
        if not text.startswith("[") or not text.endswith("]"):
            raise ParseError("metadata must be enclosed in brackets",
                             line_number)

        content = text[1:-1].strip()
        if "[" in content or "]" in content:
            raise ParseError("only one metadata block is allowed",
                             line_number)

        metadata: dict[str, str] = {}
        for pair in content.split():
            key, separator, value = pair.partition("=")
            if not separator or not key or not value:
                raise ParseError(f"invalid metadata '{pair}'", line_number)
            if key in metadata:
                raise ParseError(f"duplicate metadata '{key}'", line_number)
            metadata[key] = value
        return metadata


class MapBuilder:
    """Acumula los elementos del mapa y valida las reglas semanticas."""

    def __init__(self) -> None:
        self._drone_count: int | None = None
        self._hubs: dict[str, Hub] = {}
        self._connections: list[Connection] = []
        self._seen_connections: set[tuple[str, str]] = set()
        self._start: str | None = None
        self._end: str | None = None

    def set_drone_count(self, count: int, line_number: int) -> None:
        """Registra nd_drones (solo se permite una vez)"""
        if self._drone_count is not None:
            raise ParseError("nb_drones defined more than once", line_number)
        self._drone_count = count

    def add_hub(self, hub: Hub, role: HubRole, line_number: int) -> None:
        """Registra un hub comprobando nombre unico y start/end unicos."""
        if hub.name in self._hubs:
            raise ParseError(f"duplicate hub '{hub.name}'", line_number)

        if role is HubRole.START:
            if self._start is not None:
                raise ParseError("multiple start hubs", line_number)
            self._start = hub.name
        elif role is HubRole.END:
            if self._end is not None:
                raise ParseError("multiple end hubs", line_number)
            self._end = hub.name

        self._hubs[hub.name] = hub

    def add_connection(self, connection: Connection, line_number: int) -> None:
        """Registra una conexion entre hubs ya definidos."""
        for name in (connection.source, connection.target):
            if name not in self._hubs:
                raise ParseError(
                    f"connection references unknown hub '{name}'",
                    line_number,
                )
        if connection.source == connection.target:
            raise ParseError("a hub cannot connect to itself", line_number)
        if connection.key in self._seen_connections:
            raise ParseError(
                f"duplicate connection '{connection.source}-"
                f"{connection.target}'",
                line_number,
            )
        self._seen_connections.add(connection.key)
        self._connections.append(connection)

    def build(self) -> MapData:
        """Comprueba que no falta nada y devuelve el mapa final."""
        if self._drone_count is None:
            raise ParseError("missing nb_drones declaration")
        if self._start is None:
            raise ParseError("missing start hub")
        if self._end is None:
            raise ParseError("missing end hub")
        return MapData(
            drone_count=self._drone_count,
            hubs=dict(self._hubs),
            start_hub=self._start,
            end_hub=self._end,
            connections=list(self._connections),
        )


class LineHandler(ABC):
    """Interfaz comun: cada handler eniende un tipo de linea."""

    keyword: str

    def __init__(self, metadata_parser: MetadataParser | None = None) -> None:
        self._metadata = metadata_parser or MetadataParser()

    @abstractmethod
    def handle(
        self, parts: list[str], line_number: int, builder: MapBuilder
    ) -> None:
        """Procesa una lnea ya dividida en tokens"""

    @staticmethod
    def _build(model: type[M], data: dict[str, object], line_number: int) -> M:
        """Crea un modelo Pydantic traduciendo sus errores a ParseError."""
        try:
            return model.model_validate(data)
        except ValidationError as error:
            raise ParseError(
                describe_validation_error(error), line_number
            ) from error

    @staticmethod
    def _check_keys(
        metadata: dict[str, str], valid: set[str], line_number: int
    ) -> None:
        """Rechaza claves de metadata desconocidas."""
        unknown = sorted(set(metadata) - valid)
        if unknown:
            raise ParseError(f"unknown metadata '{unknown[0]}'", line_number)


class DroneCountHandler(LineHandler):
    """Linea 'nb_dones: <entero positivo>'."""

    keyword = DRONE_COUNT_KEYWORD

    def handle(
        self, parts: list[str], line_number: int, builder: MapBuilder
    ) -> None:
        """Valida y registra el numero de drones."""
        if len(parts) != 2:
            raise ParseError(
                "expected 'nb_drones: <positive integer>'", line_number
            )
        fleet = self._build(FleetConfig, {"nb_drones": parts[1]}, line_number)
        builder.set_drone_count(fleet.nb_drones, line_number)


class HubHandler(LineHandler):
    """Lineas 'hub:' 'start_hub:' y 'end_hub:'."""
    VALID_KEYS = {"color", "zone", "max_drones"}

    def __init__(
        self,
        keyword: str,
        role: HubRole,
        metadata_parser: MetadataParser | None = None
    ) -> None:
        super().__init__(metadata_parser)
        self.keyword = keyword
        self._role = role

    def handle(
        self, parts: list[str], line_number: int, builder: MapBuilder
    ) -> None:
        """Valida una definicion de hub y la registra."""
        if len(parts) < 4:
            raise ParseError(
                f"incomplete definition: expected '{self.keyword} "
                "<name> <x> <y> [metadata]'",
                line_number,
            )

        name = parts[1]
        metadata = self._metadata.parse(parts[4:], line_number)
        self._check_keys(metadata, self.VALID_KEYS, line_number)

        raw: dict[str, object] = {
            "name": name,
            "x": parts[2],
            "y": parts[3],
            "zone_type": metadata.get("zone", "normal"),
            "color": metadata.get("color")
        }
        # En start/end max_drones se va a ignorar.
        if self._role is HubRole.REGULAR and "max_drones" in metadata:
            raw["max_drones"] = metadata["max_drones"]

        hub = self._build(Hub, raw, line_number)
        builder.add_hub(hub, self._role, line_number)


class ConnectionHandler(LineHandler):
    """Linea 'connection: <zona1>-<zona2> [max_link_capacity=N]'."""

    keyword = "connection:"
    VALID_KEYS = {"max_link_capacity"}

    def handle(
        self, parts: list[str], line_number: int, builder: MapBuilder
    ) -> None:
        """Valida una conexion y la registra."""
        if len(parts) < 2:
            raise ParseError(
                "incomplete definition: expected "
                "'connection: <zone1>-<zone2> [metadata]'",
                line_number,
            )

        ends = parts[1].split("-")
        if len(ends) != 2 or not all(ends):
            raise ParseError(
                f"invalid connection '{parts[1]}': expected "
                "'<zone1>-<zone2>' (dashes are not allowed in names)",
                line_number,
            )

        metadata = self._metadata.parse(parts[2:], line_number)
        self._check_keys(metadata, self.VALID_KEYS, line_number)
        connection = self._build(
            Connection,
            {
                "source": ends[0],
                "target": ends[1],
                "max_link_capacity": metadata.get("max_link_capacity", "1"),
            },
            line_number,
        )
        builder.add_connection(connection, line_number)


class MapParser:
    """Lee mapa y reparte cada linea al LineHandler adecuado."""

    def __init__(self, handlers: Iterable[LineHandler] | None = None) -> None:
        chosen = handlers if handlers is not None else self.default_handlers()
        self._handlers: dict[str, LineHandler] = {
            handler.keyword: handler for handler in chosen
        }

    @staticmethod
    def default_handlers() -> list[LineHandler]:
        """Handlers del formato standar de Fly-in."""
        metadata = MetadataParser()
        return [
            DroneCountHandler(metadata),
            HubHandler("start_hub:", HubRole.START, metadata),
            HubHandler("end_hub:", HubRole.END, metadata),
            HubHandler("hub:", HubRole.REGULAR, metadata),
            ConnectionHandler(metadata),
        ]

    def parse_lines(self, lines: Iterable[str]) -> MapData:
        """Parsea el contenido de un mapa ya leido (facil de testear)."""
        builder = MapBuilder()
        is_first_statement = True

        for line_number, raw_line in enumerate(lines, start=1):
            line = raw_line.strip()
            if not line or line.startswith("#"):
                continue

            parts = line.split()
            keyword = parts[0]

            if is_first_statement and keyword != DRONE_COUNT_KEYWORD:
                raise ParseError(
                    "the first line must be 'nb_drones: <positive integer>'",
                    line_number,
                )
            is_first_statement = False

            handler = self._handlers.get(keyword)
            if handler is None:
                raise ParseError(f"unknown command '{keyword}'", line_number)
            handler.handle(parts, line_number, builder)

        return builder.build()

    def parse_file(self, path: str) -> MapData:
        """Abre el archivo (con context manager) y lo parsea."""
        try:
            with open(path, encoding="utf-8") as file:
                return self.parse_lines(file)
        except (OSError, UnicodeDecodeError) as error:
            raise ParseError(f"cannot read '{path}': {error}") from error
