#include <stdio.h>

/**
 * @brief  快速幂计算a^n
 */
int fastExp(int a, int n) {
    int result = 1;
    while(n) {
        if(n & 1) {
            result *= a;
        }
        a *= a;
        n >>= 1;
    }
    return result;
}

int main() {
    // 2^18 = 262144
    printf("%d\n", fastExp(2, 18));
    return 0;
}