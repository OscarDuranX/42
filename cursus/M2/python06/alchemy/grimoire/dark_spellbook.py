# alchemy/grimoire/dark_spellbook.py

from typing import List
from .dark_validator import validate_ingredients    # Import hacia el validator


def dark_spell_allowed_ingredients() -> List[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    validation: str = validate_ingredients(ingredients)
    return f"Dark spell recorded: {spell_name}({validation})"
