# ft_transmutation_1.py

from alchemy import transmutation

# Tambien sirve: import transmutation


def main() -> None:
    print("=== Transmutation 1 ===")
    print("Import transmutation module directly")

    result: str = transmutation.lead_to_gold()
    print(f"Testing lead_to_gold: {result}")


if __name__ == "__main__":
    main()
