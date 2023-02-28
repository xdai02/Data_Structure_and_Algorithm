#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double weight;
    double value;
    double unit_value;
} Item;

Item item_create(double weight, double value) {
    Item item;
    item.weight = weight;
    item.value = value;
    item.unit_value = value / weight;
    return item;
}

static int cmp(const void *obj1, const void *obj2) {
    Item *item1 = (Item *)obj1;
    Item *item2 = (Item *)obj2;
    if (item1->unit_value > item2->unit_value) {
        return -1;
    } else if (item1->unit_value < item2->unit_value) {
        return 1;
    } else {
        return 0;
    }
}

int knapsack(Item *items, int item_num, int capacity, Item *selected_items) {
    qsort(items, item_num, sizeof(Item), cmp);

    int selected_num = 0;
    double selected_weight = 0;

    for (int i = 0; i < item_num; i++) {
        if (selected_weight + items[i].weight <= capacity) {
            selected_weight += items[i].weight;
            selected_items[selected_num] = items[i];
            selected_num++;
        } else {
            double portion = (capacity - selected_weight) / items[i].weight;
            printf("por = %.2f\n", portion);
            items[i].weight *= portion;
            items[i].value *= portion;
            selected_items[selected_num] = items[i];
            selected_num++;
            break;
        }
    }

    return selected_num;
}

int main() {
    Item items[] = {
        item_create(10, 20),
        item_create(5, 30),
        item_create(15, 15),
        item_create(10, 25),
        item_create(20, 10),
    };
    int item_num = sizeof(items) / sizeof(items[0]);
    int capacity = 30;

    Item selected_items[item_num];
    int selected_num = knapsack(items, item_num, capacity, selected_items);
    for (int i = 0; i < selected_num; i++) {
        printf("Item(weight=%.2f, value=%.2f, unit_value=%.2f\n",
               selected_items[i].weight,
               selected_items[i].value,
               selected_items[i].unit_value);
    }

    return 0;
}