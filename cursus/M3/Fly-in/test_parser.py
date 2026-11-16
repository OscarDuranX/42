"""Tests del parser, del modelo y del grafo (unittest / pytest)."""

import glob
import unittest

from errors import ParseError
from graph import Graph
from models import ZoneType
from parser import MapParser

VALID = """# comentario
nb_drones: 2
start_hub: start 0 0 [color=green max_drones=5]
hub: a 1 -1 [zone=restricted color=red]
hub: b 2 0 [max_drones=2]
hub: wall 3 0 [zone=blocked]
end_hub: goal 4 0
connection: start-a
connection: a-b [max_link_capacity=3]
connection: b-wall
connection: wall-goal
"""


def with_line(line: str) -> str:
    """Mapa minimo valido con una linea extra al final."""
    base = "nb_drones: 1\nstart_hub: s 0 0\nend_hub: e 1 0\n"
    return base + line + "\n"


class ValidMapTests(unittest.TestCase):
    """Casos correctos."""

    def test_basic_fields(self) -> None:
        data = MapParser().parse_lines(VALID.splitlines())
        self.assertEqual(data.drone_count, 2)
        self.assertEqual((data.start_hub, data.end_hub), ("start", "goal"))
        self.assertEqual(data.hubs["a"].y, -1)
        self.assertEqual(data.hubs["a"].zone_type, ZoneType.RESTRICTED)
        self.assertEqual(data.hubs["a"].movement_cost, 2)
        self.assertEqual(data.connections[1].max_link_capacity, 3)

    def test_start_end_capacity_ignored(self) -> None:
        data = MapParser().parse_lines(VALID.splitlines())
        self.assertIsNone(data.zone_capacity("start"))
        self.assertIsNone(data.zone_capacity("goal"))
        self.assertEqual(data.zone_capacity("b"), 2)

    def test_start_max_drones_zero_is_not_an_error(self) -> None:
        text = with_line("").replace("start_hub: s 0 0",
                                     "start_hub: s 0 0 [max_drones=0]")
        data = MapParser().parse_lines(text.splitlines())
        self.assertIsNone(data.zone_capacity("s"))

    def test_graph_neighbors_skip_blocked(self) -> None:
        data = MapParser().parse_lines(VALID.splitlines())
        graph = Graph(data)
        self.assertEqual(graph.neighbors("b"), ["a"])
        self.assertEqual(graph.neighbors("b", include_blocked=True),
                         ["a", "wall"])
        self.assertIsNotNone(graph.get_connection("b", "a"))
        self.assertIsNone(graph.get_connection("start", "goal"))

    def test_all_provided_maps(self) -> None:
        files = glob.glob("maps/**/*.txt", recursive=True)
        for path in files:
            with self.subTest(path=path):
                data = MapParser().parse_file(path)
                self.assertGreater(data.drone_count, 0)


class InvalidMapTests(unittest.TestCase):
    """Cada caso debe lanzar ParseError con linea y causa."""

    def assert_error(self, text: str, fragment: str,
                     line: int | None = None) -> None:
        with self.assertRaises(ParseError) as ctx:
            MapParser().parse_lines(text.splitlines())
        self.assertIn(fragment, str(ctx.exception))
        if line is not None:
            self.assertEqual(ctx.exception.line_number, line)

    def test_first_line_must_be_nb_drones(self) -> None:
        self.assert_error("start_hub: s 0 0\n", "first line", 1)

    def test_empty_file(self) -> None:
        self.assert_error("", "missing nb_drones")

    def test_bad_drone_counts(self) -> None:
        self.assert_error("nb_drones: 0\n", "greater than 0", 1)
        self.assert_error("nb_drones: abc\n", "integer", 1)
        self.assert_error("nb_drones: 1 2\n", "expected", 1)

    def test_duplicate_nb_drones(self) -> None:
        self.assert_error(with_line("nb_drones: 3"), "more than once", 4)

    def test_missing_start_or_end(self) -> None:
        self.assert_error("nb_drones: 1\nend_hub: e 0 0\n", "missing start")
        self.assert_error("nb_drones: 1\nstart_hub: s 0 0\n", "missing end")

    def test_multiple_start(self) -> None:
        self.assert_error(with_line("start_hub: s2 5 5"), "multiple start", 4)

    def test_duplicate_hub(self) -> None:
        self.assert_error(with_line("hub: s 9 9"), "duplicate hub", 4)

    def test_dash_in_name(self) -> None:
        self.assert_error(with_line("hub: my-hub 2 2"), "dashes", 4)

    def test_bad_coordinates(self) -> None:
        self.assert_error(with_line("hub: h 1.5 2"), "integer", 4)
        self.assert_error(with_line("hub: h x 2"), "integer", 4)

    def test_incomplete_hub(self) -> None:
        self.assert_error(with_line("hub: h 1"), "incomplete", 4)

    def test_bad_zone_type(self) -> None:
        self.assert_error(with_line("hub: h 2 2 [zone=lava]"),
                          "zone_type", 4)

    def test_bad_capacity(self) -> None:
        self.assert_error(with_line("hub: h 2 2 [max_drones=0]"),
                          "greater than 0", 4)
        self.assert_error(with_line("hub: h 2 2 [max_drones=x]"),
                          "integer", 4)

    def test_bad_metadata_syntax(self) -> None:
        self.assert_error(with_line("hub: h 2 2 color=red"), "brackets", 4)
        self.assert_error(with_line("hub: h 2 2 [color=red"), "brackets", 4)
        self.assert_error(with_line("hub: h 2 2 [color]"), "invalid", 4)
        self.assert_error(with_line("hub: h 2 2 [color=]"), "invalid", 4)
        self.assert_error(with_line("hub: h 2 2 [color=a color=b]"),
                          "duplicate metadata", 4)
        self.assert_error(with_line("hub: h 2 2 [color=a] [zone=normal]"),
                          "one metadata block", 4)
        self.assert_error(with_line("hub: h 2 2 [foo=1]"),
                          "unknown metadata", 4)

    def test_connection_errors(self) -> None:
        self.assert_error(with_line("connection: s-zzz"), "unknown hub", 4)
        self.assert_error(with_line("connection: s-e\nconnection: e-s"),
                          "duplicate connection", 5)
        self.assert_error(with_line("connection: s-s"), "itself", 4)
        self.assert_error(with_line("connection: s"), "invalid connection", 4)
        self.assert_error(with_line("connection: s-e-x"),
                          "invalid connection", 4)
        self.assert_error(with_line("connection:"), "incomplete", 4)
        self.assert_error(with_line("connection: s-e [max_link_capacity=0]"),
                          "greater than 0", 4)
        self.assert_error(with_line("connection: s-e [zone=normal]"),
                          "unknown metadata", 4)

    def test_connection_before_hub_definition(self) -> None:
        text = "nb_drones: 1\nconnection: s-e\nstart_hub: s 0 0\n"
        self.assert_error(text, "unknown hub", 2)

    def test_unknown_command(self) -> None:
        self.assert_error(with_line("bogus: 1"), "unknown command", 4)

    def test_missing_file(self) -> None:
        with self.assertRaises(ParseError):
            MapParser().parse_file("no_such_file.txt")


if __name__ == "__main__":
    unittest.main()
