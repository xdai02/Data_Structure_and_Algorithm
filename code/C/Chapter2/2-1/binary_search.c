#include <stdio.h>

typedef int T;

int binary_search(T *arr, int n, T key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    T arr[] = {7, 9, 20, 34, 40, 85, 91, 93};
    int n = sizeof(arr) / sizeof(arr[0]);
    T key = 34;
    printf("index = %d\n", binary_search(arr, n, key));
    return 0;
}