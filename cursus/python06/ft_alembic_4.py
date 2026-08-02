import alchemy


def main() -> None:
    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")

    # Air deberia estar disponible
    air_result: str = alchemy.create_air()
    print(f"Testing create_air: {air_result}")

    print("Now show that not all functions can be reached")
    print("This will raise an exception!")

    # Aqui se provoca el AttributeError esperado
    print("Testing the hidden create_earth:")
    print(alchemy.create_earth())   # Esto debe fallar


if __name__ == "__main__":
    main()
