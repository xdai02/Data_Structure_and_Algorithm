class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value

def knapsack(items, capacity):
    values = [[0 for _ in range(capacity + 1)] for _ in range(len(items) + 1)]

    for i in range(1, len(items) + 1):
        for j in range(1, capacity + 1):
            if items[i - 1].weight > j:
                values[i][j] = values[i - 1][j]
            else:
                values[i][j] = max(
                    values[i - 1][j - items[i - 1].weight] + items[i - 1].value,
                    values[i - 1][j]
                )

    return values[len(items)][capacity]

items = [
    Item(2, 3),
    Item(3, 4), 
    Item(4, 5),
    Item(5, 8),
    Item(9, 10)
]
capacity = 20

print(knapsack(items, capacity))