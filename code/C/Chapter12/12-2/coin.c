#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_min_coins_recursive(int *coins, int coin_num, int price) {
    if (price <= 0) {
        return 0;
    }

    int min_coins = INT_MAX - 1;

    for (int i = 0; i < coin_num; i++) {
        if (price >= coins[i]) {
            min_coins = __min(get_min_coins_recursive(coins, coin_num, price - coins[i]) + 1, min_coins);
        }
    }

    return min_coins;
}

int get_min_coins_dp(int *coins, int coin_num, int price) {
    int dp[price + 1];
    dp[0] = 0;

    for (int i = 1; i <= price; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < coin_num; j++) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                dp[i] = __min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }

    return dp[price];
}

int main() {
    int coins[] = {2, 5, 7};
    int coin_num = sizeof(coins) / sizeof(coins[0]);
    int price = 27;
    printf("%d\n", get_min_coins_recursive(coins, coin_num, price));
    printf("%d\n", get_min_coins_dp(coins, coin_num, price));
    return 0;
}