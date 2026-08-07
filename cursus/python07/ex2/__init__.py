from .strategies import (
        BattleStrategy,
        NormalStrategy,
        AggressiveStrategy,
        DefensiveStrategy,
)

from .exceptions import InvalidBattleStrategyError

# Alias  para el Tipado!!
Normal = NormalStrategy
Aggressive = AggressiveStrategy
Defensive = DefensiveStrategy

__all__ = [
    "BattleStrategy",
    "NormalStrategy]",
    "AggressiveStrategy]",
    "DefensiveStrategy]",
    "InvalidBattleStrategyError",
]
