#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *p1, const void *p2) {
    int *num1 = (int *)p1;
    int *num2 = (int *)p2;
    return *num1 - *num2;
}

int get_min_coins(int *coins, int n, int price, int *solution) {
    qsort(coins, n, sizeof(int), cmp);

    int min_coins = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (price >= coins[i]) {
            solution[min_coins] = coins[i];
            min_coins++;
            price -= coins[i];
        }
    }

    return min_coins;
}

int main() {
    int coins[] = {1, 5, 10, 25, 100};
    int n = sizeof(coins) / sizeof(coins[0]);
    int price = 36;
    int solution[n];

    int min_coins = get_min_coins(coins, n, price, solution);
    for (int i = 0; i < min_coins; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");

    return 0;
}