from ex0 import FlameFactory, AquaFactory, CreatureFactory


def test_factory(factory: CreatureFactory, label: str) -> None:
    print(f"Testing factory {label}")

    base = factory.create_base()
    evolved = factory.create_evolved()

    # base creature
    print(base.describe())
    print(base.attack())

    # evolved creature
    print(evolved.describe())
    print(evolved.attack())


def test_battle(flame_factory: CreatureFactory,
                aqua_factory: CreatureFactory) -> None:
    print("Testing battle")
    flame_base = flame_factory.create_base()
    aqua_base = aqua_factory.create_base()

    print(
        f"{flame_base.describe()}\n vs.\n"
        f"{aqua_base.describe()}\n fight!"
    )
    print(flame_base.attack())
    print(aqua_base.attack())


def main() -> None:
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()

    # Test each factory
    test_factory(flame_factory, "Flameling")
    print()
    test_factory(aqua_factory, "Aquabub")
    print()
    # Test battle between base creatures
    test_battle(flame_factory, aqua_factory)


if __name__ == "__main__":
    main()
