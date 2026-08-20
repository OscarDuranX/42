import sys


def main() -> None:
    print("=== Player Score Analytics ===")

    args = sys.argv[1:]

    if len(args) == 0:
        print("No scores provided.", end=" ")
        print(f"Usage: python3 {sys.argv[0]} <score1> <score2> ...")
        return
    scores: list[int] = []

    for raw in args:
        try:
            score = int(raw)
            scores.append(score)
        except ValueError:
            print(f"Invalid parameter: '{raw}'")
    if len(scores) == 0:
        print("No scores provided.", end=" ")
        print(f"Usage: python3 {sys.argv[0]} <score1> <score2> ...")
        return
    total_players = len(scores)
    total_score = sum(scores)
    average_score = total_score / total_players
    high_score = max(scores)
    low_score = min(scores)
    score_range = high_score - low_score

    print(f"Scores processed: {scores}")
    print(f"Total players: {total_players}")
    print(f"Total score: {total_score}")
    print(f"Average score: {round(average_score, 1)}")
    print(f"High score: {high_score}")
    print(f"Low score: {low_score}")
    print(f"Score range: {score_range}")


if __name__ == "__main__":
    main()
