#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef int T;

/**
 * Merge Sort (original v1.0)
 */
T *merge_sort(T *arr, int n) {
    if (n <= 1) {
        return arr;
    }

    int mid = n / 2;
    T left_half[mid];
    T right_half[n - mid];

    for (int i = 0; i < mid; i++) {
        left_half[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right_half[i - mid] = arr[i];
    }

    merge_sort(left_half, mid);
    merge_sort(right_half, n - mid);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < mid && j < n - mid) {
        if (left_half[i] < right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < mid) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n - mid) {
        arr[k] = right_half[j];
        j++;
        k++;
    }

    return arr;
}

/**
 * Binary Insertion Sort
 */
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

/**
 * Merge Sort (optimized v2.0)
 */
// T *merge_sort(T *arr, int n) {
//     if (n <= 10) {
//         return insertion_sort(arr, n);
//     }

//     int mid = n / 2;
//     T left_half[mid];
//     T right_half[n - mid];

//     for (int i = 0; i < mid; i++) {
//         left_half[i] = arr[i];
//     }
//     for (int i = mid; i < n; i++) {
//         right_half[i - mid] = arr[i];
//     }

//     merge_sort(left_half, mid);
//     merge_sort(right_half, n - mid);

//     int i = 0;
//     int j = 0;
//     int k = 0;

//     while (i < mid && j < n - mid) {
//         if (left_half[i] < right_half[j]) {
//             arr[k] = left_half[i];
//             i++;
//         } else {
//             arr[k] = right_half[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < mid) {
//         arr[k] = left_half[i];
//         i++;
//         k++;
//     }

//     while (j < n - mid) {
//         arr[k] = right_half[j];
//         j++;
//         k++;
//     }

//     return arr;
// }

/**
 * Helper function for Merge Sort
 */
// static void merge(T *arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     T left_half[n1];
//     T right_half[n2];

//     for (int i = 0; i < n1; i++) {
//         left_half[i] = arr[left + i];
//     }
//     for (int i = 0; i < n2; i++) {
//         right_half[i] = arr[mid + i + 1];
//     }

//     int i = 0;
//     int j = 0;
//     int k = left;

//     while (i < n1 && j < n2) {
//         if (left_half[i] < right_half[j]) {
//             arr[k] = left_half[i];
//             i++;
//         } else {
//             arr[k] = right_half[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         arr[k] = left_half[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = right_half[j];
//         j++;
//         k++;
//     }
// }

/**
 * Merge Sort (optimized v3.0)
 */
// T *merge_sort(T *arr, int n) {
//     if (n <= 10) {
//         return insertion_sort(arr, n);
//     }

//     int current_size = 1;
//     while (current_size < n - 1) {
//         int left = 0;
//         while (left < n - 1) {
//             int mid = min(left + current_size - 1, n - 1);
//             int right = min(left + 2 * current_size - 1, n - 1);
//             merge(arr, left, mid, right);
//             left = right + 1;
//         }
//         current_size *= 2;
//     }

//     return arr;
// }

int main() {
    int arr[] = {39, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}