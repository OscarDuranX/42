from data_generator import FuncMageDataGenerator


def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """Return artifcats sorted by descending power."""
    return sorted(
        artifacts,
        key=lambda artifcats: artifcats["power"],
        reverse=True,
    )


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """Return mages whose power meets the requested minimum."""
    return list(
        filter(
            lambda mage: mage["power"] >= min_power,
            mages,
        )
    )


def spell_transformer(spells: list[str]) -> list[str]:
    """Wrap every spell name with asterisks."""
    return list(
        map(
            lambda spell: f"*{spell}*",
            spells,
        )
    )


def mage_stats(mages: list[dict]) -> dict:
    """Return maximum, minimum, and average mage power."""
    strongest_mage = max(
        mages,
        key=lambda mage: mage["power"],
    )

    weakest_mage = min(
        mages,
        key=lambda mage: mage["power"],
    )

    total_power = sum(
        map(
            lambda mage: mage["power"],
            mages,
        )
    )

    return {
        "max_power": strongest_mage,
        "min_power": weakest_mage,
        "avg_power": round(total_power / len(mages), 2),
    }


def main() -> None:
    artifacts = FuncMageDataGenerator.generate_artifacts(4)
    mages = FuncMageDataGenerator.generate_mages(5)
    spells = FuncMageDataGenerator.generate_spells(4)

    print(artifact_sorter(artifacts))
    print("\nTesting artifact sorter...\n")

    sorted_artifacts = artifact_sorter(artifacts)

    for artefact in sorted_artifacts:
        print(f"{artefact['name']} ({artefact['power']} power)")

    print(f"\n{power_filter(mages, 75)}")
    print("\nTesting power filter...\n")

    filtered_mages = power_filter(mages, 75)

    for mage in filtered_mages:
        print(f"{mage['name']} ({mage['power']} power)")

    print(f"\n{spell_transformer(spells)}")
    print("\nTesting spell transformer...\n")

    transformed_spells = spell_transformer(spells)
    print("".join(transformed_spells), end="\n\n")

    stats_mages = mage_stats(mages)

    print(stats_mages)

    print("Testing Mage Stats...\n")
    print(
        f"Best Mage: {stats_mages['max_power']}\n"
        f"Shit Mage: {stats_mages['min_power']}\n"
        f"Average power: {stats_mages['avg_power']}"
    )


if __name__ == "__main__":
    main()
