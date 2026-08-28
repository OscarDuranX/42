# ft_transmutation_0.py

import alchemy.transmutation.recipes as recipes


def main() -> None:
    print("=== Transmutation 0 ===")
    print("Using file alchemy/transmutation/recipes.py directly")

    result: str = recipes.lead_to_gold()
    print(f"Testing lead_to_gold: {result}")


if __name__ == "__main__":
    main()
