# alchemy/grimoire/dark_validator.py

from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed = dark_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()
    valid = any(ing in ingredients_lower for ing in allowed)
    status = "VALID" if valid else "INVALID"
    return f"{ingredients}-{status}"
