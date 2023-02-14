#include <iostream>

using namespace std;

const int INSERTION_SORT_THRESHOLD = 10;

/**
 * Binary Insertion Sort
 */
template <typename T>
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

/**
 * Merge Sort (original v1.0)
 */
template <typename T>
T *merge_sort(T *arr, int n) {
    if (n <= 1) {
        return arr;
    }

    int mid = n / 2;
    T left_half[mid];
    T right_half[n - mid];
    memcpy(left_half, arr, mid * sizeof(T));
    memcpy(right_half, arr + mid, (n - mid) * sizeof(T));

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
 * Merge Sort (optimized v2.0)
 */
// template <typename T>
// T *merge_sort(T *arr, int n) {
//     if (n <= INSERTION_SORT_THRESHOLD) {
//         return insertion_sort(arr, n);
//     }

//     int mid = n / 2;
//     T left_half[mid];
//     T right_half[n - mid];
//     memcpy(left_half, arr, mid * sizeof(T));
//     memcpy(right_half, arr + mid, (n - mid) * sizeof(T));

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

int main() {
    int arr[] = {39, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}