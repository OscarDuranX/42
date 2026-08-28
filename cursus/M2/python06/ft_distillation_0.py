# ft_destillation_0.py

from alchemy.potions import strength_potion, healing_potion


def main() -> None:
    print("=== Distillation 0 ===")
    print("Direct access to alchemy/potions.py")

    sp = strength_potion()
    print(f"Testing strength_potion: {sp}")

    hp = healing_potion()
    print(f"Testing healing_potion: {hp}")


if __name__ == "__main__":
    main()
