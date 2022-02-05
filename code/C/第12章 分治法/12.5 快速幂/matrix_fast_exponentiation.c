#include <stdio.h>

#define N 2

void matrixMultiply(int a[N][N], int b[N][N]) {
    int c[N][N] = {0};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j] = c[i][j];
        }
    }
}

int matrixFastExp(int n) {
    int result[N][N] = {
        {1, 1},
        {1, 0}
    };
    int M[N][N] = {
        {1, 1},
        {1, 0}
    };

    while(n > 0) {
        if(n & 1) {
            matrixMultiply(result, M);
        }
        matrixMultiply(M, M);
        n >>= 1;
    }

    return result[0][0];
}

int main() {
    for(int i = 1; i <= 10; i++) {
        printf("%d ", matrixFastExp(i-2));
    }
    printf("\n");
    return 0;
}