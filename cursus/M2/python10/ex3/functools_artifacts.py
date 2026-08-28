from data_generator import FuncMageDataGenerator

from functools import reduce, partial, lru_cache, singledispatch
from operator import add, mul
from collections.abc import Callable
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    """Reduce spell powers using the requested operation."""
    if not spells:
        return 0

    operations: dict[str, Callable[[int, int], int]] = {
        "add": add,
        "multiply": mul,
        "max": max,
        "min": min,
    }

    if operation not in operations:
        raise ValueError(f"Unknown operation: {operation}")

    selected_operation = operations[operation]
    return reduce(selected_operation, spells)


Enchantment = Callable[[int, str, str], str]
TargetEnchantment = Callable[[str], str]


def partial_enchanter(
        base_enchantment: Enchantment,
        ) -> dict[str, TargetEnchantment]:
    """Create three enchantments with fixed power and element."""

    fire = partial(base_enchantment, 50, "fire")
    ice = partial(base_enchantment, 50, "ice")
    lightning = partial(base_enchantment, 50, "lightning")

    return {
        "fire": fire,
        "ice": ice,
        "lightning": lightning,
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    """Return the nth Fibonacci number using memoization."""
    if n < 0:
        raise ValueError("n must be a non-negative integer")

    if n < 2:
        return n

    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    """Create a dispatcher based on the type of spell data."""

    @singledispatch
    def dispatch(spell: Any) -> str:
        return "Unknown spell type"

    @dispatch.register
    def _(spell: int) -> str:
        return f"Damage spell: {spell} damage"

    @dispatch.register
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @dispatch.register(list)
    def _(spell: list[Any]) -> str:
        return f"Multi-cast: {len(spell)} spells"

    return dispatch


def base_enchantment(power: int, element: str, target: str) -> str:
    """Create an enchantment description."""
    return f"{element.title()} enchantment hits {target} for {power} power"


def main() -> None:

    print("Testing spell reducer...")
    spell_powers = FuncMageDataGenerator.generate_spell_powers(4)

    try:
        print(f"Spell powers: {spell_powers}")
        print(f"Sum: {spell_reducer(spell_powers, 'add')}")
        print(f"Product: {spell_reducer(spell_powers, 'multiply')}")
        print(f"Max: {spell_reducer(spell_powers, 'max')}")
        print(f"Min: {spell_reducer(spell_powers, 'min')}")
        print(f"Empty list: {spell_reducer([], 'add')}")
        print(spell_reducer(spell_powers, "divide"))
    except ValueError as error:
        print(error)

    print("\nTesting partial enchanter...")
    enchantments = partial_enchanter(base_enchantment)
    targets = FuncMageDataGenerator.generate_spells(3)

    print(enchantments["fire"](targets[0]))
    print(enchantments["ice"](targets[1]))
    print(enchantments["lightning"](targets[2]))

    print("\nTesting memoized Fibonacci...")
    fibonacci_tests = [0, 1, 10, 15]

    for number in fibonacci_tests:
        print(f"Fib({number}): {memoized_fibonacci(number)}")

    memoized_fibonacci(15)
    print(f"Cache info: {memoized_fibonacci.cache_info()}")

    print("\nTesting spell dispatcher...")
    dispatcher = spell_dispatcher()
    random_power = FuncMageDataGenerator.generate_spell_powers(1)[0]
    random_spell = FuncMageDataGenerator.generate_spells(1)[0]
    multi_cast = FuncMageDataGenerator.generate_spells(3)

    print(dispatcher(random_power))
    print(dispatcher(random_spell))
    print(dispatcher(multi_cast))
    print(dispatcher({"power": random_power}))


if __name__ == "__main__":
    main()
