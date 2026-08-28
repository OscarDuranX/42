from abc import ABC, abstractmethod
from typing import List

from ex0.creature import Creature
from ex1.creatures import Sproutling, Bloomelle, Shiftling, Morphagon
from .exceptions import InvalidBattleStrategyError


class BattleStrategy(ABC):
    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        raise NotImplementedError

    @abstractmethod
    def act(self, creature: Creature) -> list[str]:
        raise NotImplementedError


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        # Adecuado para cualquier criatura
        return True

    def act(self, creature: Creature) -> List[str]:
        # Siempre es valido
        return [creature.attack()]


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        # Solo valido para criaturas con transformacion
        return isinstance(creature, (Shiftling, Morphagon))

    def act(self, creature: Creature) -> List[str]:
        if not self.is_valid(creature):
            raise InvalidBattleStrategyError(creature.name, "aggressive")

        actions: List[str] = []
        actions.append(creature.transform())    # type: ignore[attr-defined]
        actions.append(creature.attack())
        actions.append(creature.revert())   # type: ignore[attr-defined]
        return actions


class DefensiveStrategy(BattleStrategy):
    def is_valid(seld, creature: Creature) -> bool:
        # Solo para criaturas con curacion
        return isinstance(creature, (Sproutling, Bloomelle))

    def act(self, creature: Creature) -> List[str]:
        if not self.is_valid(creature):
            raise InvalidBattleStrategyError(creature.name, "defensive")

        actions: List[str] = []
        actions.append(creature.attack())
        actions.append(creature.heal())     # type: ignore[attr-defined]
        return actions
