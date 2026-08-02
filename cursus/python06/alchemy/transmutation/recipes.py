# alchemy/transmutation/recipes.py

# relative import: desde el paquete alchemy hacia su submodulos
from ..elements import create_air
from ..potions import strength_potion

# absolute import: desde la raiz del proyecto
from elements import create_fire


def lead_to_gold() -> str:
    air: str = create_air()
    strength: str = strength_potion()
    fire: str = create_fire()
    return (
        "Recipe transmuting Lead to Gold: "
        f"brew '{air}' and '{strength}' mixed with '{fire}'"
    )
