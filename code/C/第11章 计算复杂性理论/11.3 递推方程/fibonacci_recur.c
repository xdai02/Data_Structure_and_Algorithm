#include <stdio.h>

int fibonacci(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n-2) + fibonacci(n-1);
}

int main() {
    int n = 7;
    printf("斐波那契数列第%d位：%d\n", n, fibonacci(n));
    return 0;
}