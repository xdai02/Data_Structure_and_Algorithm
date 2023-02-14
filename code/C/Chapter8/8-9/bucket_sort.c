#include <stdio.h>
#include <stdlib.h>

typedef int T;

int cmp(const void *a, const void *b) {
    return *(T *)a - *(T *)b;
}

T *bucket_sort(T *arr, int n) {
    if (n == 0) {
        return arr;
    }

    T max_val = arr[0];
    T min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int bucket_size = (max_val - min_val) / n + 1;
    T **buckets = (T **)malloc(n * sizeof(T *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (T *)calloc(n + 1, sizeof(T));
    }

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min_val) / bucket_size;
        buckets[index][0]++;
        buckets[index][buckets[index][0]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        qsort(buckets[i] + 1, buckets[i][0], sizeof(T), cmp);
    }

    int i = 0;
    for (int j = 0; j < n; j++) {
        for (int k = 1; k <= buckets[j][0]; k++) {
            arr[i++] = buckets[j][k];
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);

    return arr;
}

int main() {
    int arr[] = {18, 11, 28, 45, 23, 49};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}