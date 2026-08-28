# alchemy/grimoire/light_validator.py

from typing import List


def validate_ingredients(ingredients: str, allowed: List[str]) -> str:
    # Pasamos todo a minusculas para comparacion case-insensitive
    ingredients_lower = ingredients.lower()

    valid = any(ing in ingredients_lower for ing in allowed)
    status = "VALID" if valid else "INVALID"
    return f"{ingredients}-{status}"
