#include <stdio.h>
#include <limits.h>

int coins[] = {2, 5, 7};
int n = sizeof(coins) / sizeof(coins[0]);

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinCoins(int price) {
    // 0元钱只需要0枚硬币
    if(price == 0) {
        return 0;
    }
    // 初始化为无穷大
    int coinNum = INT_MAX - 1;
    // 最后一枚硬币是2元
    if(price >= 2) {
        coinNum = min(getMinCoins(price-2) + 1, coinNum);
    }
    // 最后一枚硬币是5元
    if(price >= 5) {
        coinNum = min(getMinCoins(price-5) + 1, coinNum);
    }
    // 最后一枚硬币是7元
    if(price >= 7) {
        coinNum = min(getMinCoins(price-7) + 1, coinNum);
    }
    return coinNum;
}

int main() {
    int price = 27;
    printf("%d\n", getMinCoins(price));
    return 0;
}