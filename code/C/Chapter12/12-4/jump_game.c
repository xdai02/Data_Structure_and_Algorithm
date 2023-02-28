#include <stdio.h>
#include <stdbool.h>

bool can_jump(int *stones, int n) {
    bool can_jump[n];
    can_jump[0] = true;

    for (int j = 1; j < n; j++) {
        can_jump[j] = false;
        for (int i = 0; i < j; i++) {
            if (can_jump[i] && i + stones[i] >= j) {
                can_jump[j] = true;
                break;
            }
        }
    }
    return can_jump[n - 1];
}

int main() {
    int stones[] = {2, 3, 1, 1, 4};
    int n = sizeof(stones) / sizeof(stones[0]);
    if (can_jump(stones, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}