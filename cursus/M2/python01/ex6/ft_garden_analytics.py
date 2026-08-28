class Plant:
    class _Stats:
        def __init__(self) -> None:
            self.grow_calls = 0
            self.age_calls = 0
            self.show_calls = 0

        def display(self) -> None:
            print(
                    f"Stats: {self. grow_calls} grow, "
                    f"{self.age_calls} age, "
                    f"{self.show_calls} show"
            )

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
        self._stats = Plant._Stats()

    def grow(self) -> None:
        self.height += 8
        self._stats.grow_calls += 1

    def age_one_day(self) -> None:
        self.age += 1
        self._stats.age_calls += 1

    def show(self) -> None:
        self._stats.show_calls += 1
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age} days old")

    @staticmethod
    def is_older_than_year(age_in_days: int) -> bool:
        return age_in_days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.has_bloomed = False

    def bloom(self) -> None:
        self.has_bloomed = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if not self.has_bloomed:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self.seed_count = 0

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seed_count}")

    def grow(self) -> None:
        self.height += 30
        self._stats.grow_calls += 1

    def age_one_day(self) -> None:
        self.age += 20
        self._stats.age_calls += 1


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int, trunk_diameter:
                 float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self._shade_calls = 0

    def produce_shade(self) -> None:
        self._shade_calls += 1
        print(
                f"Tree {self.name} now produces a shade of "
                f"{round(self.height, 1)}cm long and {self.trunk_diameter}cm"
                " wide."
                )


def display_plant_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant._stats.display()
    if isinstance(plant, Tree):
        print(f" {plant._shade_calls} shade")


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")
    print()
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_plant_stats(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    display_plant_stats(rose)
    print()
    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_plant_stats(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_plant_stats(oak)
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age_one_day()
    sunflower.bloom()
    sunflower.seed_count = 42
    sunflower.show()
    display_plant_stats(sunflower)
    print()
    print("=== Anonymous")
    unknown = Plant.create_anonymous()
    unknown.show()
    display_plant_stats(unknown)
