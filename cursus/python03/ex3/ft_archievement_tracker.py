import random

ACHIEVEMENTS = [
    "Crafting Genius",
    "Strategist",
    "World Savior",
    "Speed Runner",
    "Survivor",
    "Master Explorer",
    "Treasure Hunter",
    "Unstoppable",
    "First Steps",
    "Collector Supreme",
    "Untouchable",
    "Sharp Mind",
    "Boss Slayer",
    "Hidden Path Finder",
    "Hacker to 42",
    "The Best",
    "Hulk",
    "43",
    "Survivor To 42",
    "1to1 OctoVsYou"
]


def gen_player_achievements() -> set[str]:
    count = random.randint(4, 10)

    chosen = random.sample(ACHIEVEMENTS, count)

    return set(chosen)


def main() -> None:
    print("=== Achievement Tracker System ===", end="\n\n")

    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}", end="\n\n")

    all_distinct = alice.union(bob, charlie, dylan)
    print(f"All distinct archievements: {all_distinct}", end="\n\n")

    common = alice.intersection(bob, charlie, dylan)
    print(f"Common achievements: {common}", end="\n\n")

    only_alice = alice.difference(bob.union(charlie, dylan))
    only_bob = bob.difference(alice.union(charlie, dylan))
    only_charlie = charlie.difference(alice.union(bob, dylan))
    only_dylan = dylan.difference(alice.union(bob, charlie))

    print(f"Only Alice has: {only_alice}")
    print(f"Only Bob has: {only_bob}")
    print(f"Only Charlie has: {only_charlie}")
    print(f"Only Dylan has: {only_dylan}", end="\n\n")

    alice_missing = all_distinct.difference(alice)
    bob_missing = all_distinct.difference(bob)
    charlie_missing = all_distinct.difference(charlie)
    dylan_missing = all_distinct.difference(dylan)

    print(f"Alice is missing: {alice_missing}")
    print(f"Bob is missing: {bob_missing}")
    print(f"Charlie is missing: {charlie_missing}")
    print(f"Dylan is missing: {dylan_missing}")


if __name__ == "__main__":
    main()
