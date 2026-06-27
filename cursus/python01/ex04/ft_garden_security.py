class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def set_height(self, new_height: float) -> None:
        if new_height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new_height
            print(f"Height updated: {new_height}cm")

    def set_age(self, new_age: int) -> None:
        if new_age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = new_age
            print(f"Age updated: {new_age} days")

    def show(self) -> None:
        print(
                f"{self.name}: {round(self.get_height(), 1)}cm, "
                f"{self.get_age()} days old"
                )


if __name__ == "__main__":
    rose = Plant("Rose", 15.0, 10)
    print("=== Garden Security System ===")
    print("Plant created: ", end="")
    rose.show()
    print("")
    rose.set_height(25.0)
    rose.set_age(30)
    print("")
    rose.set_height(-5.0)
    rose.set_age(-10)
    print("")
    print("Current state: ", end="")
    rose.show()
