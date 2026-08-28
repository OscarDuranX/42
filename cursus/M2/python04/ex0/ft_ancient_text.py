import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return

    filename = sys.argv[1]
    print("=== CYber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        f: IO[str] = open(filename, "r", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return

    try:
        print("---", end="\n\n")
        content = f.read()
        print(content, end="\n")
        print("---")
    finally:
        f.close()
        print(f"File '{filename}' closed.")


if __name__ == "__main__":
    main()
