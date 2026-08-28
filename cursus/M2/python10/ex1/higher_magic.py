import random

from collections.abc import Callable

Spell = Callable[[str, int], str]


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def shield(target: str, power: int) -> str:
    return f"Shield protects {target} with {power} power"


def spell_combiner(spell1: Spell, spell2: Spell) -> Callable[[str, int],
                                                             tuple[str, str]]:
    """Create a spell that casts two spells with the same arguments."""

    def combined_spell(target: str, power: int) -> tuple[str, str]:
        return (
            spell1(target, power),
            spell2(target, power),
        )

    return combined_spell


def power_amplifier(base_spell: Spell, multiplier: int) -> Spell:
    """Return a spell with amplified power."""

    def amplified_spell(target: str, power: int) -> str:
        amplified_power = power * multiplier
        return base_spell(target, amplified_power)

    return amplified_spell


def conditional_caster(
    condition: Callable[[str, int], bool],
        spell: Spell,
            ) -> Spell:
    """Return a spell that only runs when its condition succeeds."""

    def conditional_spell(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"

    return conditional_spell


def spell_sequence(spells: list[Spell]
                   ) -> Callable[[str, int], list[str]]:
    """Return a spell that casts every received spell in order."""

    def sequence_spell(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]

    return sequence_spell


def main() -> None:
    targets = ["Dragon", "Goblin", "Wizard", "Knight"]

    target = random.choice(targets)
    power = random.randint(5, 25)

    print("Testing spell combiner...\n")
    combined1 = spell_combiner(fireball, heal)
    combined2 = spell_combiner(fireball, shield)
    print(f"Combined spell result 1: {combined1(target, power)}")
    print(f"Combined spell result 2: {combined2(target, power)}\n")

    print("\nTesting power amplifier...\n")
    mega_fireball = power_amplifier(fireball, 3)
    print(f"Original: {fireball(target, power)}")
    print(f"Amplified: {mega_fireball(target, power)}")

    print("\nTesting conditional caster...\n")
    high_power_only = conditional_caster(
        lambda current_target, current_power: current_power >= 15,
        fireball,
    )
    print(high_power_only(target, 10))
    print(high_power_only(target, 20))

    print("\nTesting spell sequence...\n")
    cast_all = spell_sequence([fireball, heal, shield])

    for result in cast_all(target, power):
        print(result)


if __name__ == "__main__":
    main()
