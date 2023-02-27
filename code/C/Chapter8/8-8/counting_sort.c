#include <stdio.h>
#include <stdlib.h>

int *counting_sort(int *arr, int n) {
    if (n == 0) {
        return arr;
    }

    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int range = max_val - min_val + 1;
    int *counts = (int *)calloc(range, sizeof(int));
    if (counts == NULL) {
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        counts[arr[i] - min_val]++;
    }

    int cnt = 0;
    for (int i = 0; i < range; i++) {
        while (counts[i]--) {
            arr[cnt] = i + min_val;
            cnt++;
        }
    }

    free(counts);
    return arr;
}

int main() {
    int arr[] = {95, 94, 91, 98, 99, 90, 99, 93, 91, 92};
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}