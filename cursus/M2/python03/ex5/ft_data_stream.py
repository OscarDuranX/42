import random
from typing import Generator


PLAYERS = ["alice", "bob", "charlie", "dylan"]
ACTIONS = ["run", "eat", "sleep", "grab", "move", "climb", "swim",
           "release", "use"]


def gen_event() -> Generator[tuple[str, str], None, None]:
    while True:
        name = random.choice(PLAYERS)
        action = random.choice(ACTIONS)
        yield (name, action)


def consume_event(events: list[tuple[str, str]]) -> Generator[tuple[str, str],
                                                              None, None]:
    while len(events) > 0:
        idx = random.randrange(len(events))
        event = events.pop(idx)
        yield event


def main() -> None:
    print("=== Game Data Stream Processor ===")

    event_gen = gen_event()

    for i in range(1000):
        name, action = next(event_gen)
        print(f"Event {i}: Player {name} did action {action}")

    events_list: list[tuple[str, str]] = []

    for _ in range(10):
        events_list.append(next(event_gen))

    print(f"Built list of 10 events: {events_list}")
    for event in consume_event(events_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events_list}")


if __name__ == "__main__":
    main()
