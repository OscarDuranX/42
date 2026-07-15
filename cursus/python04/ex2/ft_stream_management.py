import sys
from typing import IO, Optional


def read_file(filename: str) -> Optional[str]:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        f: IO[str] = open(filename, 'r', encoding="utf-8")
    except OSError as e:
        msg = f"[STDERR] Error opening file '{filename}': {e}\n"
        sys.stderr.write(msg)
        sys.stderr.flush()
        return None

    try:
        print("---", end="\n\n")
        content = f.read()
        print(content)
        print("---")
    finally:
        f.close()
        print(f"File '{filename}' closed.", end="\n\n")
    return content


def transform_content(content: str) -> None:
    print("Transform data:")
    print("---")

    lines = content.splitlines(keepends=True)
    transformed_lines = [line.rstrip("\n") + "#" + ("\n" if line.endswith("\n")
                                                    else "") for line in lines]
    transformed = "".join(transformed_lines)
    print(transformed)
    print("---")
    print("Enter new filename (or empty):", end="")
    sys.stdout.flush()

    line = sys.stdin.readline()
    if line == "":
        new_name = ""
    else:
        new_name = line.rstrip("\n")

    if new_name == "":
        print("Not saving data.")
        return
    print(f"Saving data to '{new_name}'")

    try:
        out: IO[str] = open(new_name, "w", encoding="utf-8")
    except OSError as e:
        msg = f"[STDERR] Error opening file '{new_name}': {e}\n"
        sys.stderr.write(msg)
        sys.stderr.flush()
        print("Data not saved.")
        return

    try:
        out.write(transformed)
    finally:
        out.close()
        print(f"Data saved in file '{new_name}'.")


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return

    content = read_file(sys.argv[1])
    if content is None:
        return
    transform_content(content)


if __name__ == "__main__":
    main()
