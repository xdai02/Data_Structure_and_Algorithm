#include <stdio.h>
#define ITEM_NUM 5
#define CAPACITY 20

int max(int a, int b) {
    return a > b ? a : b;
}

int getMaxValue(int *weight, int *value) {
    int b[ITEM_NUM+1][CAPACITY+1] = {{0}};

    for(int k = 1; k <= ITEM_NUM; k++) {
        for(int c = 1; c <= CAPACITY; c++) {
            if(weight[k] > c) {
                b[k][c] = b[k-1][c];
            } else {
                b[k][c] = max(b[k-1][c-weight[k]] + value[k], b[k-1][c]);
            }
        }
    }
    return b[ITEM_NUM][CAPACITY];
}

int main() {
    int weight[] = {0, 2, 3, 4, 5, 9};
    int value[] = {0, 3, 4, 5, 8, 10};
    printf("%d\n", getMaxValue(weight, value));
}