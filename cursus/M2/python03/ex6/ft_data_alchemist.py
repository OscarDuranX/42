import random

PLAYERS = [
    "Alice",
    "bob",
    "Charlie",
    "dylan",
    "Emma",
    "Gregory",
    "john",
    "kevin",
    "Liam",
]


def capitalized_player_name() -> list[str]:
    all_capitalized = [name.capitalize() for name in PLAYERS]
    print(f"New list with all name capitalized: {all_capitalized}")

    capitalized_only = [name for name in PLAYERS if name.istitle()]
    print(f"New list of capitalized name only: {capitalized_only}", end="\n\n")

    return all_capitalized


def scores(players_list: list[str]) -> None:
    score_dict = {name: random.randint(0, 1000) for name in players_list}
    print(f"Score dict: {score_dict}")
    total_score = sum(score_dict.values())
    count = len(score_dict)
    average = total_score / count if count > 0 else 0.0
    print(f"Score average is {round(average, 2)}")
    high_scores = {name: score for name, score in score_dict.items() if score >
                   average}
    print(f"High scores: {high_scores}")


def main() -> None:
    print("=== Game Data Alchemist ===", end="\n\n")
    print(f"Initial list of players: {PLAYERS}")

    capi_name_players = capitalized_player_name()

    scores(capi_name_players)


if __name__ == "__main__":
    main()
