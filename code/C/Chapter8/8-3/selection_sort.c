#include <stdio.h>

typedef int T;

#define swap(x, y)  \
    {               \
        T temp = x; \
        x = y;      \
        y = temp;   \
    }

/**
 * Selection Sort (original v1.0)
 */
T *selection_sort(T *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    return arr;
}

/**
 * Selection Sort (optimzed v2.0)
 */
// T *selection_sort(T *arr, int n) {
//     for (int i = 0; i < n / 2; i++) {
//         int minIndex = i;
//         int maxIndex = n - i - 1;

//         for (int j = i; j < n - i; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//             if (arr[j] > arr[maxIndex]) {
//                 maxIndex = j;
//             }
//         }

//         swap(arr[i], arr[minIndex]);

//         // In case of i == maxIndex before swap(arr[i], arr[minIndex]), it's now at minIndex.
//         if (i == maxIndex) {
//             maxIndex = minIndex;
//         }

//         swap(arr[n - i - 1], arr[maxIndex]);
//     }

//     return arr;
// }

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}