class InvalidBattleStrategyError(Exception):
    """Raised when a strategy is applied to an invalid creature."""

    def __init__(self, creature_name: str, strategy_name: str) -> None:
        message = (
                f"Invalid Creature '{creature_name}' "
                f"for this {strategy_name} strategy"
        )
        super().__init__(message)
