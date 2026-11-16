"""Punto de entrada de Fly-in."""

import sys

from errors import ParseError
from graph import Graph
from parser import MapParser


def main() -> int:
    """Lee el mapa indicado por argumento y muestra un resumen."""
    if len(sys.argv) != 2:
        print("Usage: python3 main.py <map_file>", file=sys.stderr)
        return 1

    try:
        game_map = MapParser().parse_file(sys.argv[1])
    except ParseError as error:
        print(f"Error: {error}", file=sys.stderr)
        return 1

    graph = Graph(game_map)
    print(f"Drones: {game_map.drone_count}")
    print(f"Start: {game_map.start_hub}  ->  End: {game_map.end_hub}")
    for name in game_map.hubs:
        print(f"{name}: {graph.neighbors(name)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
