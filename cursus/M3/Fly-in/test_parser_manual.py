from parser import parse_file
from graph import Graph

def main() -> None:
    """Prueba manual del parser con un mapa válido."""
    game_map = parse_file("maps/02_simple_fork.txt")

    print("Drones:", game_map.drone_count)
    print("Start:", game_map.start_hub)
    print("End:", game_map.end_hub)

    print("\nHubs:")
    for name, hub in game_map.hubs.items():
        print(
            f"- {name}: ({hub.x}, {hub.y}), "
            f"type={hub.zone_type}, "
            f"color={hub.color}, "
            f"capacity={hub.max_drones}"
        )

    print("\nConnections:")
    for connection in game_map.connections:
        print(
            f"- {connection.source} <-> {connection.target}, "
            f"capacity={connection.max_link_capacity}"
        )

    graph = Graph(game_map)

    for hub_name in game_map.hubs:
        print(f"{hub_name} -> {graph.neighbors(hub_name)}")


if __name__ == "__main__":
    main()
