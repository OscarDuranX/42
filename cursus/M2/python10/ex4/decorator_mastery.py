from data_generator import FuncMageDataGenerator

from collections.abc import Callable
from functools import wraps
from time import perf_counter
from typing import Any


def spell_timer(func: Callable[..., Any]) -> Callable[..., Any]:
    """Measure and print the execution time of a spell."""

    @wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start_time = perf_counter()

        result = func(*args, **kwargs)

        elapsed_time = perf_counter() - start_time
        print(f"Spell completed in {elapsed_time:.3f} seconds")
        return result

    return wrapper


def power_validator(min_power: int) -> Callable[[Callable[..., Any]],
                                                Callable[..., Any]]:
    """Create a decorator that checks a spell's minimum power."""

    def decorator(func: Callable[..., Any]) -> Callable[..., Any]:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs.get("power")

            if power is None:
                power = args[-1]

            if power < min_power:
                return "Insufficient power for this spell"

            return func(*args, **kwargs)

        return wrapper

    return decorator


def retry_spell(max_attempts: int) -> Callable[[Callable[..., Any]],
                                               Callable[..., Any],]:
    """Create a decorator that retries a failed spell."""
    def decorator(func: Callable[..., Any]) -> Callable[..., Any]:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(
                            "Spell failed, retrying..."
                            f"(attempt {attempt}/{max_attempts})"
                        )

            return (
                "Spell casting failed after "
                f"{max_attempts} attempts\n"
                "Waaargssssshhh se ha desinflado el globo!!"
            )

        return wrapper

    return decorator


class MageGuild:
    """Represent a guild that validates and casts spells."""

    @staticmethod
    def validate_mage_name(name: str) -> bool:
        """Return whether a mage name contains only letters and spaces."""
        return len(name) >= 3 and all(
            character.isalpha() or character.isspace()
            for character in name
        )

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        """Cast a spell when it has sufficient power."""
        return f"Successfully cast {spell_name} with {power} power"


def main() -> None:
    """Run demonstrations for all Exercise 4 requirements."""
    spell_names = FuncMageDataGenerator.generate_spells(3)
    powers = FuncMageDataGenerator.generate_spell_powers(4)
    mage_names = FuncMageDataGenerator.MAGE_NAMES[:2]
    invalid_names = ["Jo", "Alex123", "Test@Name"]

    print("Testing spell timer...")

    @spell_timer
    def fireball() -> str:
        return f"{spell_names[0].title()} cast!"

    print(f"Result: {fireball()}")

    print("\nTesting power validator...")

    @power_validator(min_power=10)
    def test_spell(power: int) -> str:
        return f"{spell_names[1].title()} cast with {power} power"

    valid_power = max(powers)
    invalid_power = 5

    print(test_spell(valid_power))
    print(test_spell(invalid_power))

    print("\nTesting retry spell...")

    @retry_spell(max_attempts=3)
    def failed_spell() -> str:
        raise ValueError("The spell failed")

    print(failed_spell())

    print("\nTesting MageGuild...")
    guild = MageGuild()

    for name in mage_names + invalid_names:
        print(f"{name}: {MageGuild.validate_mage_name(name)}")

    print(guild.cast_spell(spell_names[2], valid_power))
    print(guild.cast_spell(spell_names[2], invalid_power))


if __name__ == "__main__":
    main()
