#include <iostream>

using namespace std;

/**
 * Bubble Sort (original v1.0)
 */
template <typename T>
T *bubble_sort(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

/**
 * Bubble Sort (optimized v2.0)
 */
// template <typename T>
// T *bubble_sort(T *arr, int n) {
//     for (int i = 0; i < n; i++) {
//         bool swapped = false;
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
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
 * Bubble Sort (optimized v2.1)
 */
// template <typename T>
// T *bubble_sort(T *arr, int n) {
//     int right = n - 1;
//     for (int i = 0; i < n; i++) {
//         bool swapped = false;
//         int last = 0;
//         for (int j = 0; j < right; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
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
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}