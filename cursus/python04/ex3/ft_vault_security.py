from typing import Tuple, Optional


def secure_archive(
        filename: str,
        action: str = "read",
        content_to_write: Optional[str] = None,
        ) -> Tuple[bool, str]:
    if action == "read":
        try:
            with open(filename, "r", encoding="utf-8") as f:
                data = f.read()
            return True, data
        except OSError as e:
            return False, str(e)
    elif action == "write":
        if content_to_write is None:
            return False, "No content provided to write"

        try:
            with open(filename, "w", encoding="utf-8") as f:
                f.write(content_to_write)
            return True, "Content successfully written to file"
        except OSError as e:
            return False, str(e)
    else:
        return False, f"Unknown action: {action}"


def main() -> None:
    print("=== Cyber Archives Security ===", end="\n\n")

    result = secure_archive("/not/existing/file", "read")
    print("Using 'secure_archive' to read from a nonexistent file:", result,
          end="\n\n")
    result = secure_archive("prova", "read")
    print("Using 'secure_archive' to read from a inaccessible file:", result,
          end="\n\n")

    result = secure_archive("test.txt", "read")
    print("Using 'secure_archive' to read from a regular file:\n", result,
          end="\n\n")

    if result[0]:
        previus_content = result[1]
        result2 = secure_archive("prova.txt", "write", previus_content)
        print("Using 'secure_archive' to write previous content to a new file:"
              "\n", result2)


if __name__ == "__main__":
    main()
