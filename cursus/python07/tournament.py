from typing import List, Tuple

from ex0 import FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    Normal,
    Aggressive,
    Defensive,
    BattleStrategy,
    InvalidBattleStrategyError,
)
from ex0.factories import CreatureFactory

Opponent = Tuple[CreatureFactory, BattleStrategy]


def strategy_label(strategy: BattleStrategy) -> str:
    name = strategy.__class__.__name__
    return name.removesuffix("Strategy")


def run_tournament(label: str, opponents: List[Opponent]) -> None:

    opponents_str_parts: list[str] = []
    for factory, strategy in opponents:
        creature = factory.create_base()
        opponents_str_parts.append(
                f"({creature.name}+{strategy_label(strategy)})"
                )
    opponents_str = ", ".join(opponents_str_parts)

    print(f"{label}\n[ {opponents_str} ]")
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    try:
        # i recorre la lista
        for i in range(len(opponents)):
            factory_a, strategy_a = opponents[i]
            creature_a = factory_a.create_base()
            # j solo toma valores mayores que i -> pares unicos
            for j in range(i + 1, len(opponents)):
                factory_b, strategy_b = opponents[j]
                creature_b = factory_b.create_base()

                print("\n* Battle *")
                print(creature_a.describe())
                print(" vs.")
                print(creature_b.describe())
                print(" now fight!")

                # Acciones de A
                for action in strategy_a.act(creature_a):
                    print(action)

                # Acciones de B
                for action in strategy_b.act(creature_b):
                    print(action)
    except InvalidBattleStrategyError as error:
        print(f"Battle error, aborting tournament: {error}")


def main() -> None:
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    normal = Normal()
    aggressive = Aggressive()
    defensive = Defensive()

    # Tournament 0: basic
    tournament0_opponents: List[Opponent] = [
        (flame_factory, normal),
        (healing_factory, defensive),
    ]
    run_tournament("Tournament0 (basic)", tournament0_opponents)
    print()

    # Tournament 1: error (Flameling + Aggressive)
    tournament1_opponents: List[Opponent] = [
         (flame_factory, aggressive),
         (healing_factory, defensive),
    ]
    run_tournament("Tournament1 (error)", tournament1_opponents)
    print()

    # Tournament 2: multiple
    tournament2_opponents: List[Opponent] = [
        (aqua_factory, normal),
        (healing_factory, defensive),
        (transform_factory, aggressive),
    ]
    run_tournament("Tournament2 (multiple)", tournament2_opponents)


if __name__ == "__main__":
    main()
