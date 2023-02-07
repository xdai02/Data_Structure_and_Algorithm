#include <stdio.h>

void buy(int n, int money) {
    for (int x = 0; x <= n / 5; x++) {
        for (int y = 0; y <= n / 3; y++) {
            int z = n - x - y;
            if (z > 0 && z % 3 == 0 && 5 * x + 3 * y + z / 3 == money) {
                printf("x = %d, y = %d, z = %d\n", x, y, z);
            }
        }
    }
}

int main() {
    buy(100, 100);
    return 0;
}