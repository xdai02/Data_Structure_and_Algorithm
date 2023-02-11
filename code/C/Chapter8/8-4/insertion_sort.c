#include <stdio.h>

/**
 * Insertion Sort
 */
int *insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    return arr;
}

/**
 * Binary Insertion Sort
 */
// int* insertion_sort(int* arr, int n) {
//     for (int i = 1; i < n; i++) {
//         int temp = arr[i];
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

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}