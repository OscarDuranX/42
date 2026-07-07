def input_temperature(temp_str: str) -> int:
    temp_int = int(temp_str)
    return temp_int


def test_temperature() -> None:
    print("=== Garden Temperature ===", end="\n\n")

    valid_input = "25"
    print(f"Input date is '{valid_input}'")
    temp = input_temperature(valid_input)
    print(f"Temperature is now {temp}°C", end="\n\n")

    invalid_intput = "abc"
    print(f"Input data is '{invalid_intput}'")
    try:
        temp = input_temperature(invalid_intput)
        print(f"Temperature is now {temp}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")

    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
