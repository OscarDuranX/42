import sys


def parse_arguments(args: list[str]) -> tuple[dict[str, int], list[str]]:
    inventory: dict[str, int] = {}
    order: list[str] = []

    for raw in args:
        if ":" not in raw or raw.count(":") != 1:
            print(f"Error - invalid parameter '{raw}'")
            continue

        name, qty_str = raw.split(":")

        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue

        try:
            qty = int(qty_str)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
            continue
        inventory[name] = qty
        order.append(name)

    return inventory, order


def compute_and_print_stats(inventory: dict[str, int],
                            order: list[str]) -> None:
    print(f"Got inventory: {inventory}")

    items = list(inventory.keys())
    print(f"Item list: {items}")

    total_quantity = sum(inventory.values())
    print(f"Total quantity of the {len(items)} items: {total_quantity}")
    for name in items:
        qty = inventory[name]
        percentage = ((qty / total_quantity) * 100 if total_quantity > 0 else
                      0.0)
        print(f"Item {name} represents {round(percentage, 1)}%")

    pairs = [(name, inventory[name]) for name in order]

    most_name, most_qty = max(pairs, key=lambda p: p[1])
    least_name, least_qty = min(pairs, key=lambda p: p[1])

    print(f"Item most abundant: {most_name} with quantity {most_qty}")
    print(f"Item least abundant: {least_name} with quantity {least_qty}")


def main() -> None:
    print("=== Inventory System Analysis ===")

    args = sys.argv[1:]
    inventory, order = parse_arguments(args)

    compute_and_print_stats(inventory, order)

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
