#include <stdio.h>
#include <stdlib.h>

int cmp(const void *_a, const void *_b) {
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *b - *a;
}

/**
 * @brief  最少硬币找零
 * @param  coins: 硬币面值
 * @param  n: 硬币种类数量
 * @param  price: 找零数量
 * @param  minCoin: 最少硬币数量
 * @retval 找零方式
 */
int* getMinCoins(int *coins, int n, int price, int *minCoin) {
    qsort(coins, n, sizeof(int), cmp);

    *minCoin = 0;
    int *solution = (int *)malloc(sizeof(int) * price);
    if(!solution) {
        return NULL;
    }
    
    for(int i = 0; i < n; i++) {
        int num = price / coins[i];
        for(int j = 0; j < num; j++) {
            solution[(*minCoin)++] = coins[i];
        }
        price -= coins[i] * num;
        if(price <= 0) {
            break;
        }
    }
    return solution;
}

int main() {
    int coins[] = {1, 5, 10, 25, 100};
    int n = sizeof(coins) / sizeof(coins[0]);
    int price = 36;
    int minCoin = 0;        // 最少硬币数量

    int *solution = getMinCoins(coins, n, price, &minCoin);
    if(!solution) {
        exit(1);
    }
    for(int i = 0; i < minCoin; i++) {
        printf("%d ", solution[i]);
    }
    free(solution);
    return 0;
}