from models import Connection, MapData


class Graph:
    """Representa las conexiones bidireccionales entre hubs."""

    def __init__(self, map_data: MapData) -> None:
        self.map_data = map_data
        self._adjacency: dict[str, list[Connection]] = {
            hub_name: []
            for hub_name in map_data.hubs
        }
        self._by_key: dict[tuple[str, str], Connection] = {}

        for connection in map_data.connections:
            self._adjacency[connection.source].append(connection)
            self._adjacency[connection.target].append(connection)
            self._by_key[connection.key] = connection

    def connections_of(self, hub_name: str) -> list[Connection]:
        """Devuelve las conexiones que salen de hub_name."""
        return list(self._adjacency[hub_name])

    def neighbors(
            self, hub_name: str, include_blocked: bool = False
    ) -> list[str]:
        """Devuelve los hubs vecinos de hub_name.

        Por defecto omite las zonas blocked, porque ningun dron puede
        entrar en ellas.
        """
        names = [
            connection.other_end(hub_name)
            for connection in self._adjacency[hub_name]
        ]
        if include_blocked:
            return names
        return [
            name for name in names
            if not self.map_data.hubs[name].is_blocked
        ]

    def get_connection(self, first: str, second: str) -> Connection | None:
        """Devuelve la conecion entre dos hubs, o None si no existe"""
        key = tuple(sorted((first, second)))
        return self._by_key.get((key[0], key[1]))
