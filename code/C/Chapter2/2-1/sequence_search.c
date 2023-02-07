#include <stdio.h>

typedef int T;

int sequence_search(T *arr, int n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    T arr[] = {40, 9, 20, 93, 7, 34, 85, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    T key = 34;
    printf("index = %d\n", sequence_search(arr, n, key));
    return 0;
}