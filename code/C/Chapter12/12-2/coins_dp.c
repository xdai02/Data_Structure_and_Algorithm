#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinCoins(int *coins, int n, int price) {
    int f[price+1];
    
    f[0] = 0;
    for(int i = 1; i <= price; i++) {
        f[i] = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(i >= coins[j] && f[i - coins[j]] != INT_MAX) {
                f[i] = min(f[i - coins[j]] + 1, f[i]);
            }
        }
    }

    if(f[price] == INT_MAX) {
        f[price] = -1;
    }
    return f[price];
}

int main() {
    int coins[] = {2, 5, 7};
    int n = sizeof(coins) / sizeof(coins[0]);
    int price = 27;
    printf("%d\n", getMinCoins(coins, n, price));
    return 0;
}