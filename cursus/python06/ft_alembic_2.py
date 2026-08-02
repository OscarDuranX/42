import alchemy.elements as alchemy_elements


def main() -> None:
    print("=== Almbic 2 ===")
    print("Accessing alchemy/elements.py using 'import ...' structure")

    result: str = alchemy_elements.create_earth()
    print(f"Testing create_earth: {result}")


if __name__ == "__main__":
    main()
