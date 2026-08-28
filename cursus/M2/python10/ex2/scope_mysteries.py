from collections.abc import Callable
from typing import Any
from data_generator import FuncMageDataGenerator


def mage_counter() -> Callable[[], int]:
    """Create an independent count closure."""
    count = 0

    def increment() -> int:
        nonlocal count
        count += 1
        return count

    return increment


def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    total_power = initial_power

    def add_power(amount: int) -> int:
        nonlocal total_power
        total_power += amount
        return total_power

    return add_power


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    def enchant(item_name: str) -> str:
        return f"{enchantment_type}{item_name}"

    return enchant


def memory_vault() -> dict[str, Callable[..., Any]]:
    memories: dict[str, object] = {}

    def store(key: str, value: object) -> None:
        memories[key] = value

    def recall(key: str) -> object | str:
        return memories.get(key, "Memory not found")

    return {
        "store": store,
        "recall": recall,
    }


def main() -> None:

    print("Testing mage counter...")
    counter_a = mage_counter()
    counter_b = mage_counter()

    print(f"Counter A call 1: {counter_a()}")
    print(f"Counter A call 2: {counter_a()}")
    print(f"Counter B call 1: {counter_b()}")

    print("\nTesting spell accumulator...")
    initial_power = 100
    power_additions = [20, 30]

    accumulator = spell_accumulator(initial_power)

    for amount in power_additions:
        total = accumulator(amount)
        print(f"Base {initial_power}, add {amount}: {total}")

    print("\nTesting enchantment factory...")
    enchantment_types = FuncMageDataGenerator.ENCHANTMENT_TYPES[:2]
    items = FuncMageDataGenerator.generate_enchantment_items(2)

    first_enchantment = enchantment_factory(enchantment_types[0])
    second_enchantment = enchantment_factory(enchantment_types[1])

    print(first_enchantment(items[0]))
    print(second_enchantment(items[1]))

    print("\nTesting memory vault...")
    vault = memory_vault()
    store = vault["store"]
    recall = vault["recall"]

    store("secret", 42)
    print("Store 'secret' = 42")
    print(f"Recall 'secret': {recall('secret')}")
    print(f"Recall 'unknown': {recall('unknown')}")


if __name__ == "__main__":
    main()
