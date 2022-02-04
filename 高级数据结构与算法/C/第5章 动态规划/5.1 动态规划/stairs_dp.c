#include <stdio.h>

int climbStairs(int n) {
    if(n <= 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else if(n == 2) {
        return 2;
    }
    int num1 = 1;
    int num2 = 2;
    int sum;
    for(int i = 3; i <= n; i++) {
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
    return sum;
}

int main() {
    printf("%d\n", climbStairs(10));
    return 0;
}