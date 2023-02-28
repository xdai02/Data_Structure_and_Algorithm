#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
    public:
    double weight;
    double value;
    double unit_value;

    Item(double weight, double value) {
        this->weight = weight;
        this->value = value;
        this->unit_value = value / weight;
    }

    bool operator>(const Item &item) const {
        return this->unit_value > item.unit_value;
    }

    friend ostream &operator<<(ostream &os, const Item &item) {
        os << "Item(weight=" << item.weight << ", value=" << item.value << ", unit_value=" << item.unit_value << ")";
        return os;
    }
};

vector<Item> knapsack(vector<Item> items, int capacity) {
    sort(items.begin(), items.end(), greater<Item>());

    vector<Item> selected_items;
    double selected_weight = 0;

    for (Item item : items) {
        if (selected_weight + item.weight <= capacity) {
            selected_weight += item.weight;
            selected_items.push_back(item);
        } else {
            double portion = (capacity - selected_weight) / item.weight;
            item.weight *= portion;
            item.value *= portion;
            selected_items.push_back(item);
            break;
        }
    }

    return selected_items;
}

int main() {
    vector<Item> items = {
        Item(10, 20),
        Item(5, 30),
        Item(15, 15),
        Item(10, 25),
        Item(20, 10),
    };
    int capacity = 30;

    vector<Item> selected_items = knapsack(items, capacity);
    for (Item item : selected_items) {
        cout << item << endl;
    }

    return 0;
}