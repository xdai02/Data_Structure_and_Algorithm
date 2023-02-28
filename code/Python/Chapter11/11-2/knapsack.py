class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value
        self.unit_value = value / weight
    
    def __str__(self):
        return "Item(weight=%d, value=%d, unit_value=%.2f)" % (
            self.weight, self.value, self.unit_value
        )

def knapsack(items, capacity):
    items.sort(key=lambda x: x.unit_value, reverse=True)

    selected_items = []
    selected_weight = 0

    for item in items:
        if selected_weight + item.weight <= capacity:
            selected_weight += item.weight
            selected_items.append(item)
        else:
            portion = (capacity - selected_weight) / item.weight
            item.weight *= portion
            item.value *= portion
            selected_items.append(item)
            break

    return selected_items

items = [
    Item(10, 20),
    Item(5, 30), 
    Item(15, 15),
    Item(10, 25),
    Item(20, 10)
]
capacity = 30

selected_items = knapsack(items, capacity)
for item in selected_items:
    print(item)