# ft_distillation_1.py

import alchemy


def main() -> None:
    print("=== Distillation 1 ===")
    print("Using: 'import alchemy' structure to access potions")

    sp = alchemy.strength_potion()
    print(f"Testing strength_potion: {sp}")

    h = alchemy.heal()
    print(f"Testing heal alias: {h}")


if __name__ == "__main__":
    main()
