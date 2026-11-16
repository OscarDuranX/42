"""Prueba manual del parser con un mapa valido."""

from graph import Graph
from parser import MapParser


def main() -> None:
    """Imprime el contenido parseado de un mapa y sus vecinos."""
    game_map = MapParser().parse_file("maps/02_simple_fork.txt")

    print("Drones:", game_map.drone_count)
    print("Start:", game_map.start_hub)
    print("End:", game_map.end_hub)

    print("\nHubs:")
    for name, hub in game_map.hubs.items():
        print(
            f"- {name}: ({hub.x}, {hub.y}), type={hub.zone_type.value}, "
            f"color={hub.color}, capacity={game_map.zone_capacity(name)}"
        )

    print("\nConnections:")
    for connection in game_map.connections:
        print(
            f"- {connection.source} <-> {connection.target}, "
            f"capacity={connection.max_link_capacity}"
        )

    graph = Graph(game_map)
    print("\nNeighbors:")
    for hub_name in game_map.hubs:
        print(f"{hub_name} -> {graph.neighbors(hub_name)}")


if __name__ == "__main__":
    main()
