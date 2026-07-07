import sys


def main() -> None:
    print("=== CommandQuest===")

    program_name = sys.argv[0]
    print(f"Program name: {program_name}")

    total_args = len(sys.argv)

    if total_args == 1:
        print("No arguments provided!")
    else:
        num_user_args = total_args - 1
        print(f"Arguments received: {num_user_args}")

    for index, value in enumerate(sys.argv[1:], start=1):
        print(f"Argument {index}: {value}")

    print(f"Total arguments: {total_args}")


if __name__ == "__main__":
    main()
