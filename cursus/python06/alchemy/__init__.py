# alchemy/__init.py__


from .elements import create_air
from .potions import strength_potion, healing_potion
from .transmutation.recipes import lead_to_gold

# alias del healing_potion
heal = healing_potion

__all__ = ["create_air", "strength_potion", "heal", "lead_to_gold"]
