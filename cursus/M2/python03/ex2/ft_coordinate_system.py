import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        user_input = input("Enter new coordinates"
                           "as floats in format 'x,y,z': ")

        parts = user_input.split(",")
        if len(parts) != 3:
            print("Invalid syntax")
            continue

        x_str, y_str, z_str = parts

        try:
            x = float(x_str)
            y = float(y_str)
            z = float(z_str)
            return (x, y, z)
        except ValueError as e:
            for coord_str in (x_str, y_str, z_str):
                try:
                    float(coord_str)
                except ValueError:
                    print(f"Error on parameter '{coord_str}': {e}")
                    break
            continue


def main() -> None:
    print("=== Game Coordinate System ===")
    print("Get a first set of coordinates", end="\n\n")

    first_pos = get_player_pos()
    print(f"Got a first tuple: {first_pos}")

    x, y, z = first_pos
    print(f"It includes: X={x}, Y={y}, Z={z}")
    distance_to_center = math.sqrt(x**2 + y**2 + z**2)
    print(f"Distance to center: {round(distance_to_center, 4)}")
    print("")
    print("Get a second set of coordinates")
    second_pos = get_player_pos()

    x2, y2, z2 = second_pos
    x1, y1, z1 = first_pos
    distance_between = math.sqrt(
            (x2 - x1) ** 2 +
            (y2 - y1) ** 2 +
            (z2 - z1) ** 2
    )
    print("Distance between the 2 sets of coordinates: "
          f"{round(distance_between, 4)}")


if __name__ == "__main__":
    main()
