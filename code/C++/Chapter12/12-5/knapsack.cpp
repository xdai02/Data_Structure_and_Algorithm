#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Item {
    public:
    int weight;
    int value;

    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

int knapsack(vector<Item> items, int capacity) {
    int values[items.size() + 1][capacity + 1];
    memset(values, 0, sizeof(values));

    for (int i = 1; i <= (int)items.size(); i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight > j) {
                values[i][j] = values[i - 1][j];
            } else {
                values[i][j] = max(
                    values[i - 1][j - items[i - 1].weight] + items[i - 1].value,
                    values[i - 1][j]
                );
            }
        }
    }

    return values[items.size()][capacity];
}

int main() {
    vector<Item> items = {
        Item(2, 3),
        Item(3, 4),
        Item(4, 5),
        Item(5, 8),
        Item(9, 10),
    };
    int capacity = 20;

    cout << knapsack(items, capacity) << endl;
    return 0;
}