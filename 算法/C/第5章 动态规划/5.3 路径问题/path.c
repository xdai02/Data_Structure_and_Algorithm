#include <stdio.h>

int uniquePath(int m, int n) {
    int f[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0) {
                f[i][j] = 1;
            } else {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
    }
    return f[m-1][n-1];
}

int main() {
    printf("%d\n", uniquePath(4, 8));
    return 0;
}