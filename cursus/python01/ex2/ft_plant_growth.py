class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age} days old")

    def age_one_day(self) -> None:
        self.age += 1

    def grow(self) -> None:
        self.height += 0.8


if __name__ == "__main__":
    rose = Plant("Rose", 25.0, 30)

    print("=== Garden Plant Growth ===")
    rose.show()
    initial_height = rose.height

    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow()
        rose.age_one_day()
        rose.show()

    total_growth = rose.height - initial_height
    print(f"Growth this week: {round(total_growth, 1)}cm")
