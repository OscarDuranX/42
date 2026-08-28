from ex0.factories import CreatureFactory   # interfaz abstracta del ex0
from .creatures import Sproutling, Bloomelle, Shiftling, Morphagon
from ex0.creature import Creature


class HealingCreatureFactory(CreatureFactory):
    """Factory for the healing family: Sproutling/Bloomelle."""

    def create_base(self) -> Creature:
        return Sproutling()

    def create_evolved(self) -> Creature:
        return Bloomelle()


class TransformCreatureFactory(CreatureFactory):
    """Factory for the transfomr family: Shiftling/Morphagon."""

    def create_base(self) -> Creature:
        return Shiftling()

    def create_evolved(self) -> Creature:
        return Morphagon()
