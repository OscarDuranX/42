# alchemy/grimoire/light_spellbook.py

from typing import List
from .light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> List[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    allowed = light_spell_allowed_ingredients()
    validation: str = validate_ingredients(ingredients, allowed)

    # El validator devuelve algo tipo "Earth, wind and fire - VALID"
    return (
        f"Spell recorded: {spell_name}({validation})"
        if "VALID" in validation
        else f"Spell rejected: {spell_name}({validation})"
    )
