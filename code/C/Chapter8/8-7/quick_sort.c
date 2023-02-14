#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int T;

#define swap(x, y)  \
    {               \
        T temp = x; \
        x = y;      \
        y = temp;   \
    }

const int INSERTION_SORT_THRESHOLD = 10;

/**
 * Binary Insertion Sort
 */
T *insertion_sort(T *arr, int n) {
    for (int i = 1; i < n; i++) {
        T temp = arr[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (temp < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = temp;
    }

    return arr;
}

static int partition(T *arr, int start, int end, T pivot) {
    int i = start + 1;
    int j = end;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[start], arr[j]);
    return j;
}

static int median_of_three(T *arr, int start, int end) {
    int mid = start + (end - start) / 2;

    if (arr[start] > arr[mid]) {
        swap(arr[start], arr[mid]);
    }
    if (arr[start] > arr[end]) {
        swap(arr[start], arr[end]);
    }
    if (arr[mid] > arr[end]) {
        swap(arr[mid], arr[end]);
    }

    return mid;
}

/**
 * Help function for Quick Sort (original v1.0)
 */
// static void __quick_sort(T *arr, int start, int end) {
//     if (start < end) {
//         T pivot = arr[start];

//         int pivot_index = partition(arr, start, end, pivot);
//         __quick_sort(arr, start, pivot_index - 1);
//         __quick_sort(arr, pivot_index + 1, end);
//     }
// }

/**
 * Help function for Quick Sort (optimized v2.0)
 */
// static void __quick_sort(T *arr, int start, int end) {
//     if (start < end) {
//         int pivot_index = rand() % (end - start + 1) + start;
//         swap(arr[start], arr[pivot_index]);
//         T pivot = arr[start];

//         pivot_index = partition(arr, start, end, pivot);
//         __quick_sort(arr, start, pivot_index - 1);
//         __quick_sort(arr, pivot_index + 1, end);
//     }
// }

/**
 * Help function for Quick Sort (optimized v2.1)
 */
// static void __quick_sort(T *arr, int start, int end) {
//     if (start < end) {
//         int pivot_index = median_of_three(arr, start, end);
//         swap(arr[start], arr[pivot_index]);
//         T pivot = arr[start];

//         pivot_index = partition(arr, start, end, pivot);
//         __quick_sort(arr, start, pivot_index - 1);
//         __quick_sort(arr, pivot_index + 1, end);
//     }
// }

/**
 * Help function for Quick Sort (optimized v2.2)
 */
// static void __quick_sort(T *arr, int start, int end) {
//     if (end - start <= INSERTION_SORT_THRESHOLD) {
//         T temp[end - start + 1];
//         memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
//         insertion_sort(temp, end - start + 1);
//         memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
//         return;
//     }

//     int pivot_index = median_of_three(arr, start, end);
//     swap(arr[start], arr[pivot_index]);
//     T pivot = arr[start];

//     pivot_index = partition(arr, start, end, pivot);
//     __quick_sort(arr, start, pivot_index - 1);
//     __quick_sort(arr, pivot_index + 1, end);
// }

/**
 * Quick Sort
 */
T *quick_sort(T *arr, int n) {
    srand(time(NULL));
    __quick_sort(arr, 0, n - 1);
    return arr;
}

int main() {
    int arr[] = {4, 7, 6, 5, 3, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}