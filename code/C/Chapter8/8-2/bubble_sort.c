#include <stdio.h>
#include <stdbool.h>

#define SWAP(x, y)    \
    {                 \
        int temp = x; \
        x = y;        \
        y = temp;     \
    }

typedef int T;

/**
 * Bubble Sort (original)
 */
T *bubble_sort(T *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                SWAP(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

/**
 * Bubble Sort (optimized v1.0)
 */
// T *bubble_sort(T *arr, int n) {
//     for (int i = 0; i < n; i++) {
//         bool swapped = false;
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 SWAP(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }
//         if (!swapped) {
//             break;
//         }
//     }

//     return arr;
// }

/**
 * Bubble Sort (optimized v2.0)
 */
// T *bubble_sort(T *arr, int n) {
//     int right = n - 1;
//     for (int i = 0; i < n; i++) {
//         bool swapped = false;
//         int last = 0;
//         for (int j = 0; j < right; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 SWAP(arr[j], arr[j + 1]);
//                 swapped = true;
//                 last = j;
//             }
//         }
//         if (!swapped) {
//             break;
//         }
//         right = last;
//     }

//     return arr;
// }

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}