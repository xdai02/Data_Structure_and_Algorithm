#include <stdio.h>

int climbStairs(int n) {
    if(n <= 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else if(n == 2) {
        return 2;
    }
    return climbStairs(n-1) + climbStairs(n-2);
}

int main() {
    printf("%d\n", climbStairs(10));
    return 0;
}