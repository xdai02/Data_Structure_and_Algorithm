#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_min_coins_recursive(vector<int> coins, int price) {
    if (price <= 0) {
        return 0;
    }

    int min_coins = INT_MAX - 1;

    for (int coin : coins) {
        if (price >= coin) {
            min_coins = min(get_min_coins_recursive(coins, price - coin) + 1, min_coins);
        }
    }

    return min_coins;
}

int get_min_coins_dp(vector<int> coins, int price) {
    int dp[price + 1];
    dp[0] = 0;

    for (int i = 1; i <= price; i++) {
        dp[i] = INT_MAX;
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
    }

    return dp[price];
}

int main() {
    vector<int> coins = {2, 5, 7};
    int price = 27;
    cout << get_min_coins_recursive(coins, price) << endl;
    cout << get_min_coins_dp(coins, price) << endl;
    return 0;
}