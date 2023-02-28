#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int value;
} Item;

Item item_create(double weight, double value) {
    Item item;
    item.weight = weight;
    item.value = value;
    return item;
}

int knapsack(Item *items, int n, int capacity) {
    int values[n + 1][capacity + 1];
    memset(values, 0, sizeof(values));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight > j) {
                values[i][j] = values[i - 1][j];
            } else {
                values[i][j] = __max(
                    values[i - 1][j - items[i - 1].weight] + items[i - 1].value,
                    values[i - 1][j]
                );
            }
        }
    }

    return values[n][capacity];
}

int main() {
    Item items[] = {
        item_create(2, 3),
        item_create(3, 4),
        item_create(4, 5),
        item_create(5, 8),
        item_create(9, 10),
    };
    int n = sizeof(items) / sizeof(Item);
    int capacity = 20;

    printf("%d\n", knapsack(items, n, capacity));
    return 0;
}