#include <stdio.h>

long long fast_exponentiation(long long x, long long n) {
    if (n == 0) {
        return 1;
    }

    long long half;
    if (n % 2 == 0) {
        half = fast_exponentiation(x, n / 2);
        return half * half;
    } else {
        half = fast_exponentiation(x, (n - 1) / 2);
        return half * half * x;
    }
}

int main() {
    printf("%I64d\n", fast_exponentiation(2, 18));
    return 0;
}