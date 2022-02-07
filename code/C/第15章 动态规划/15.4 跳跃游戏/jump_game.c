#include <stdio.h>
#include <stdbool.h>

bool canJump(int *stone, int n) {
    bool f[n];
    f[0] = true;

    for(int j = 1; j < n; j++) {
        f[j] = false;
        for(int i = 0; i < j; i++) {
            if(f[i] && i + stone[i] >= j) {
                f[j] = true;
                break;
            }
        }
    }
    return f[n-1];
}

int main() {
    int stone[] = {2, 3, 1, 1, 4};
    int n = sizeof(stone) / sizeof(stone[0]);
    if(canJump(stone, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}