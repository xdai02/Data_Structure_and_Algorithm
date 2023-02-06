#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double monte_pi(int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        double x = rand() / (RAND_MAX + 1.0);   // [0, 1]
        double y = rand() / (RAND_MAX + 1.0);   // [0, 1]
        if(sqrt(x*x + y*y) <= 1) {
            cnt++;
        }
    }
    return 4.0 * cnt / n;
}

int main() {
    srand(time(NULL));
    printf("PI = %f\n", monte_pi(10000000));
    return 0;
}