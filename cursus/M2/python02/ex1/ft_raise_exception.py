def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)

    if temp < 0:
        raise Exception(f"{temp}°C is too cold for plants (min 0°C)")
    if temp > 40:
        raise Exception(f"{temp}°C is too hot for plants (max 40°C)")
    return temp


def test_temperature() -> None:
    print("=== Garden Temperature ===", end="\n\n")

    valid_input = "25"
    print(f"Input date is '{valid_input}'")
    temp = input_temperature(valid_input)
    print(f"Temperature is now {temp}°C")
    print()
    invalid_str = "abc"
    print(f"Input data is '{invalid_str}'")
    try:
        temp = input_temperature(invalid_str)
        print(f"Temperature is now {temp}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    too_hot = "100"
    print()
    print(f"Input data is '{too_hot}'")
    try:
        temp = input_temperature(too_hot)
        print(f"Temperature is now {temp}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    too_cold = "-50"
    print()
    print(f"Input data is '{too_cold}'")
    try:
        temp = input_temperature(too_cold)
        print(f"Temperature is now {temp}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
