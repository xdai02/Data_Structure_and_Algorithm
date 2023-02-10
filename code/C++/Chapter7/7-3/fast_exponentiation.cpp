#include <iostream>

using namespace std;

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
    cout << fast_exponentiation(2, 18) << endl;
    return 0;
}