from models import Connection, MapData


class Graph:
    """Representa las conexiones bidireccionales entre hubs."""


    def __init__(self, map_data: MapData) -> None:
        self.map_data = map_data
        self.adjacency: dict[str, list[Connection]] = {
            hub_name: []
            for hub_name in map_data.hubs
        }

    def neighbors(self, hub_name: str) -> list[str]:
        """Devuelve los nombres de los hubs conectados a hub_name"""
        neighbors: list[str] = []

        for connection in self.adjacency[hub_name]:
            if connection.source == hub_name:
                neighbors.append(connection.target)
            else:
                neighbors.append(connection.source)

        return neighbors
