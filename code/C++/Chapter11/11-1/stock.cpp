#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int> prices) {
    int profit = 0;
    for (int i = 0; i < (int)prices.size() - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << max_profit(prices) << endl;
    return 0;
}