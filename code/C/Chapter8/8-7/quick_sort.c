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

/**
 * Partition function for Quick Sort (original v1.0)
 */
static int partition(T *arr, int start, int end) {
    T pivot = arr[start];

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

/**
 * Help function for Quick Sort (original v1.0)
 */
static void __quick_sort(T *arr, int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        __quick_sort(arr, start, pivot - 1);
        __quick_sort(arr, pivot + 1, end);
    }
}

/**
 * Quick Sort (original v1.0)
 */
T *quick_sort(T *arr, int n) {
    __quick_sort(arr, 0, n - 1);
    return arr;
}

// /**
//  * Partition function for Quick Sort (optimized v2.0)
//  */
// static int partition(T *arr, int start, int end) {
//     int pivot_index = rand() % (end - start + 1) + start;
//     swap(arr[start], arr[pivot_index]);
//     T pivot = arr[start];

//     int i = start + 1;
//     int j = end;
//     while (i <= j) {
//         while (i <= j && arr[i] <= pivot) {
//             i++;
//         }
//         while (i <= j && arr[j] >= pivot) {
//             j--;
//         }
//         if (i <= j) {
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[start], arr[j]);
//     return j;
// }

// /**
//  * Help function for Quick Sort (optimized v2.0)
//  */
// static void __quick_sort(T *arr, int start, int end) {
//     if (start < end) {
//         int pivot = partition(arr, start, end);
//         __quick_sort(arr, start, pivot - 1);
//         __quick_sort(arr, pivot + 1, end);
//     }
// }

// /**
//  * Quick Sort (optimized v2.0)
//  */
// T *quick_sort(T *arr, int n) {
//     srand(time(NULL));
//     __quick_sort(arr, 0, n - 1);
//     return arr;
// }

// /**
//  * Pivot chosen function for Quick Sort (optimized v2.1)
//  */
// static int median_of_three(T *arr, int start, int end) {
//     int mid = start + (end - start) / 2;

//     if (arr[start] > arr[mid]) {
//         swap(arr[start], arr[mid]);
//     }
//     if (arr[start] > arr[end]) {
//         swap(arr[start], arr[end]);
//     }
//     if (arr[mid] > arr[end]) {
//         swap(arr[mid], arr[end]);
//     }

//     return mid;
// }

// /**
//  * Partition function for Quick Sort (optimized v2.1)
//  */
// static int partition(T *arr, int start, int end) {
//     int pivot_index = median_of_three(arr, start, end);
//     swap(arr[start], arr[pivot_index]);
//     T pivot = arr[start];

//     int i = start + 1;
//     int j = end;
//     while (i <= j) {
//         while (i <= j && arr[i] <= pivot) {
//             i++;
//         }
//         while (i <= j && arr[j] >= pivot) {
//             j--;
//         }
//         if (i <= j) {
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[start], arr[j]);
//     return j;
// }

// /**
//  * Help function for Quick Sort (optimized v2.1)
//  */
// static void __quick_sort(T *arr, int start, int end) {
//     if (start < end) {
//         int pivot = partition(arr, start, end);
//         __quick_sort(arr, start, pivot - 1);
//         __quick_sort(arr, pivot + 1, end);
//     }
// }

// /**
//  * Quick Sort (optimized v2.1)
//  */
// T *quick_sort(T *arr, int n) {
//     __quick_sort(arr, 0, n - 1);
//     return arr;
// }

// /**
//  * Binary Insertion Sort
//  */
// T *insertion_sort(T *arr, int n) {
//     for (int i = 1; i < n; i++) {
//         T temp = arr[i];
//         int left = 0;
//         int right = i - 1;

//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (temp < arr[mid]) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }

//         for (int j = i - 1; j >= left; j--) {
//             arr[j + 1] = arr[j];
//         }
//         arr[left] = temp;
//     }

//     return arr;
// }

// /**
//  * Pivot chosen function for Quick Sort (optimized v2.2)
//  */
// static int median_of_three(T *arr, int start, int end) {
//     int mid = start + (end - start) / 2;

//     if (arr[start] > arr[mid]) {
//         swap(arr[start], arr[mid]);
//     }
//     if (arr[start] > arr[end]) {
//         swap(arr[start], arr[end]);
//     }
//     if (arr[mid] > arr[end]) {
//         swap(arr[mid], arr[end]);
//     }

//     return mid;
// }

// /**
//  * Partition function for Quick Sort (optimized v2.2)
//  */
// static int partition(T *arr, int start, int end) {
//     if (end - start <= 10) {
//         T temp[end - start + 1];
//         memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
//         insertion_sort(temp, end - start + 1);
//         memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
//         return -1;
//     }

//     int pivot_index = median_of_three(arr, start, end);
//     swap(arr[start], arr[pivot_index]);
//     T pivot = arr[start];

//     int i = start + 1;
//     int j = end;
//     while (i <= j) {
//         while (i <= j && arr[i] <= pivot) {
//             i++;
//         }
//         while (i <= j && arr[j] >= pivot) {
//             j--;
//         }
//         if (i <= j) {
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[start], arr[j]);
//     return j;
// }

// /**
//  * Help function for Quick Sort (optimized v2.2)
//  */
// static void __quick_sort(T *arr, int start, int end) {
//     if (start < end) {
//         int pivot = partition(arr, start, end);
//         if (pivot != -1) {
//             __quick_sort(arr, start, pivot - 1);
//             __quick_sort(arr, pivot + 1, end);
//         }
//     }
// }

// /**
//  * Quick Sort (optimized v2.2)
//  */
// T *quick_sort(T *arr, int n) {
//     __quick_sort(arr, 0, n - 1);
//     return arr;
// }

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