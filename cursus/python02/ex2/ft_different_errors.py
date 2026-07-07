def garden_operations(operation_number: int) -> str:
    if operation_number == 0:
        return str(int("abc"))
    if operation_number == 1:
        result = 10 / 0
        return str(result)
    if operation_number == 2:
        with open("/non/existent/file", "r") as f:
            data = f.read()
        return data
    if operation_number == 3:
        value = "temperature: " + 10
        return value
    else:
        print("Operation completed successfully", end="\n\n")
        return "0"


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")

    for op in range(0, 5):
        try:
            print(f"Testing operation {op}...")
            garden_operations(op)
        except (ValueError, ZeroDivisionError, FileNotFoundError,
                TypeError) as e:
            print(f"Caught {type(e).__name__}: {e}")

    print("All error type tested successfully!")


if __name__ == "__main__":
    test_error_types()
