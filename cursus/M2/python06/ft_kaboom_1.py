# ft_kaboom_1.py


def main() -> None:
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly")
    print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")

    from alchemy.grimoire.dark_spellbook import dark_spell_record

    spell = dark_spell_record("Forbidden", "bats and arsenic")
    print(f"Testing record dark spell: {spell}")


if __name__ == "__main__":
    main()
