#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_min_coins(vector<int> coins, int price) {
    vector<int> solution;

    sort(coins.begin(), coins.end(), greater<int>());

    for (int i = 0; i < (int)coins.size(); i++) {
        while (price >= coins[i]) {
            solution.push_back(coins[i]);
            price -= coins[i];
        }
    }

    return solution;
}

int main() {
    vector<int> coins = {1, 5, 10, 25, 100};
    int price = 36;

    vector<int> solution = get_min_coins(coins, price);
    for (int coin : solution) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}