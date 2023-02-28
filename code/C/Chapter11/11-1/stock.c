#include <stdio.h>

int max_profit(int *prices, int n) {
    int profit = 0;
    for (int i = 0; i < n - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    printf("%d\n", max_profit(prices, n));
    return 0;
}