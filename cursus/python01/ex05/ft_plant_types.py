class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age
   
    def grow(self) -> None:
        self._height += 0.8

    def age_one_day(self) -> None:
        self._age += 1

    def show(self) -> None:
        print(f"{self.name}: {round(self._height(), 1)}cm, {self._age()} days old")

class Flower(Plant)
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
    super().__init__(name, height, age)
    self.color = color
    self.bloomed = False

    def show(self) -> None:
        super().show
        print(f"Color: {self.color}")
