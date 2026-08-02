# alchemy/potions.py

from .elements import create_earth, create_air  # import relativo
from elements import create_fire, create_water  # import absoluto


def healing_potion() -> str:
    earth: str = create_earth()
    air: str = create_air()
    return f"Healing potion brewed with '{earth}' and '{air}'"


def strength_potion() -> str:
    fire: str = create_fire()
    water: str = create_water()
    return f"Strength potion brewed with '{fire}' and '{water}'"
