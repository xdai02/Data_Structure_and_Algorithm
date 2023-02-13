#ifndef _SORT_ALGO_H_
#define _SORT_ALGO_H_

#include <iostream>
#include <cmath>

/**
 * Bubble Sort (original v1.0)
 */
template <typename T>
T *bubble_sort(T *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    return arr;
}

/**
 * Bubble Sort (optimized v2.0)
 */
template <typename T>
T *bubble_sort_opt_v1(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    return arr;
}

/**
 * Bubble Sort (optimized v2.1)
 */
template <typename T>
T *bubble_sort_opt_v2(T *arr, int n) {
    int right = n - 1;
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        int last = 0;
        for (int j = 0; j < right; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                last = j;
            }
        }
        if (!swapped) {
            break;
        }
        right = last;
    }

    return arr;
}

/**
 * Selection Sort (original v1.0)
 */
template <typename T>
T *selection_sort(T *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }

    return arr;
}

/**
 * Selection Sort (optimzed v2.0)
 */
template <typename T>
T *selection_sort_opt(T *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int minIndex = i;
        int maxIndex = n - i - 1;

        for (int j = i; j < n - i; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);

        // In case of i == maxIndex before swap(arr[i], arr[minIndex]), it's now at minIndex.
        if (i == maxIndex) {
            maxIndex = minIndex;
        }

        std::swap(arr[n - i - 1], arr[maxIndex]);
    }

    return arr;
}

/**
 * Insertion Sort (original v1.0)
 */
template <typename T>
T *insertion_sort(T *arr, int n) {
    for (int i = 1; i < n; i++) {
        T temp = arr[i];
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
 * Insertion Sort (optimized v2.0)
 */
template <typename T>
T *insertion_sort_opt(T *arr, int n) {
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
 * Shell Sort (original v1.0)
 */
template <typename T>
T *shell_sort(T *arr, int n) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }

    return arr;
}

/**
 * Shell Sort (Hibbard)
 */
template <typename T>
T *shell_sort_opt_hibbard(T *arr, int n) {
    int k = (int)log2(n);

    while (k >= 0) {
        int gap = (int)pow(2, k) - 1;
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        k--;
    }

    return arr;
}

/**
 * Shell Sort (Sedgewick)
 */
template <typename T>
T *shell_sort_opt_sedgewick(T *arr, int n) {
    int k = (int)log2(n / 3);

    while (k >= 0) {
        int gap = (int)pow(4, k) + 3 * (int)pow(2, k - 1) + 1;
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        k--;
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
 * Merge Sort (optimized v2.0)
 */
template <typename T>
T *merge_sort_opt_v1(T *arr, int n) {
    if (n <= 10) {
        return insertion_sort_opt(arr, n);
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

    merge_sort_opt_v1(left_half, mid);
    merge_sort_opt_v1(right_half, n - mid);

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
 * Helper function for Merge Sort
 */
template <typename T>
static void merge(T *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T left_half[n1];
    T right_half[n2];

    for (int i = 0; i < n1; i++) {
        left_half[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        right_half[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_half[i] < right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

/**
 * Merge Sort (optimized v3.0)
 */
template <typename T>
T *merge_sort_opt_v2(T *arr, int n) {
    if (n <= 10) {
        return insertion_sort_opt(arr, n);
    }

    int current_size = 1;
    while (current_size < n - 1) {
        int left = 0;
        while (left < n - 1) {
            int mid = std::min(left + current_size - 1, n - 1);
            int right = std::min(left + 2 * current_size - 1, n - 1);
            merge(arr, left, mid, right);
            left = right + 1;
        }
        current_size *= 2;
    }

    return arr;
}

#endif