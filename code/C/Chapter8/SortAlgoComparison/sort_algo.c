#include "sort_algo.h"
#include <math.h>
#include <time.h>
#include <string.h>

#define swap(x, y)  \
    {               \
        T temp = x; \
        x = y;      \
        y = temp;   \
    }

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct argument_t {
    T *data;
    int n;
} argument_t;

/**
 * Bubble Sort (original v1.0)
 */
void *bubble_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    for (int i = 0; i < n - 1; i++) {
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
void *bubble_sort_v2_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
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
void *bubble_sort_v2_1(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    int right = n - 1;
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        int last = 0;
        for (int j = 0; j < right; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
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
void *selection_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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
void *selection_sort_v2_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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

        swap(arr[i], arr[minIndex]);

        // In case of i == maxIndex before swap(arr[i], arr[minIndex]), it's now at minIndex.
        if (i == maxIndex) {
            maxIndex = minIndex;
        }

        swap(arr[n - i - 1], arr[maxIndex]);
    }

    return arr;
}

/**
 * Insertion Sort (original v1.0)
 */
void *insertion_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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
void *insertion_sort_v2_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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
void *shell_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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
void *shell_sort_hibbard(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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
void *shell_sort_sedgewick(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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
void *merge_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

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

    argument_t left_arg = {left_half, mid};
    argument_t right_arg = {right_half, n - mid};
    merge_sort_v1_0(&left_arg);
    merge_sort_v1_0(&right_arg);

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
void *merge_sort_v2_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    if (n <= 10) {
        return insertion_sort_v2_0(args);
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

    argument_t left_arg = {left_half, mid};
    argument_t right_arg = {right_half, n - mid};
    merge_sort_v2_0(&left_arg);
    merge_sort_v2_0(&right_arg);

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
void *merge_sort_v3_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    if (n <= 10) {
        return insertion_sort_v2_0(args);
    }

    int current_size = 1;
    while (current_size < n - 1) {
        int left = 0;
        while (left < n - 1) {
            int mid = min(left + current_size - 1, n - 1);
            int right = min(left + 2 * current_size - 1, n - 1);
            merge(arr, left, mid, right);
            left = right + 1;
        }
        current_size *= 2;
    }

    return arr;
}

/**
 * Partition function for Quick Sort (original v1.0)
 */
static int partition_v1_0(T *arr, int start, int end) {
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
static void __quick_sort_v1_0(T *arr, int start, int end) {
    if (start < end) {
        int pivot = partition_v1_0(arr, start, end);
        __quick_sort_v1_0(arr, start, pivot - 1);
        __quick_sort_v1_0(arr, pivot + 1, end);
    }
}

/**
 * Quick Sort (original v1.0)
 */
void *quick_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    __quick_sort_v1_0(arr, 0, n - 1);
    return arr;
}

/**
 * Partition function for Quick Sort (optimized v2.0)
 */
static int partition_v2_0(T *arr, int start, int end) {
    int pivot_index = rand() % (end - start + 1) + start;
    swap(arr[start], arr[pivot_index]);
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
 * Help function for Quick Sort (optimized v2.0)
 */
static void __quick_sort_v2_0(T *arr, int start, int end) {
    if (start < end) {
        int pivot = partition_v2_0(arr, start, end);
        __quick_sort_v2_0(arr, start, pivot - 1);
        __quick_sort_v2_0(arr, pivot + 1, end);
    }
}

/**
 * Quick Sort (optimized v2.0)
 */
void *quick_sort_v2_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    srand(time(NULL));
    __quick_sort_v2_0(arr, 0, n - 1);
    return arr;
}

/**
 * Pivot chosen function for Quick Sort
 */
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
 * Partition function for Quick Sort (optimized v2.1)
 */
static int partition_v2_1(T *arr, int start, int end) {
    int pivot_index = median_of_three(arr, start, end);
    swap(arr[start], arr[pivot_index]);
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
 * Help function for Quick Sort (optimized v2.1)
 */
static void __quick_sort_v2_1(T *arr, int start, int end) {
    if (start < end) {
        int pivot = partition_v2_1(arr, start, end);
        __quick_sort_v2_1(arr, start, pivot - 1);
        __quick_sort_v2_1(arr, pivot + 1, end);
    }
}

/**
 * Quick Sort (optimized v2.1)
 */
void *quick_sort_v2_1(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    __quick_sort_v2_1(arr, 0, n - 1);
    return arr;
}

/**
 * Partition function for Quick Sort (optimized v2.2)
 */
static int partition_v2_2(T *arr, int start, int end) {
    if (end - start <= 10) {
        T temp[end - start + 1];
        memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
        argument_t arg = {temp, end - start + 1};
        insertion_sort_v2_0(&arg);
        memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
        return -1;
    }

    int pivot_index = median_of_three(arr, start, end);
    swap(arr[start], arr[pivot_index]);
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
 * Help function for Quick Sort (optimized v2.2)
 */
static void __quick_sort_v2_2(T *arr, int start, int end) {
    if (start < end) {
        int pivot = partition_v2_2(arr, start, end);
        if (pivot != -1) {
            __quick_sort_v2_2(arr, start, pivot - 1);
            __quick_sort_v2_2(arr, pivot + 1, end);
        }
    }
}

/**
 * Quick Sort (optimized v2.2)
 */
void *quick_sort_v2_2(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    __quick_sort_v2_2(arr, 0, n - 1);
    return arr;
}

/**
 * Partition function for Quick Sort (optimized v3.0)
 */
static int partition_v3_0(T *arr, int start, int end) {
    int pivot_index = median_of_three(arr, start, end);
    swap(arr[start], arr[pivot_index]);
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
 * Help function for Quick Sort (optimized v3.0)
 */
static void __quick_sort_v3_0(T *arr, int start, int end) {
    if (end - start <= 10) {
        T temp[end - start + 1];
        memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
        argument_t arg = {temp, end - start + 1};
        insertion_sort_v2_0(&arg);
        memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
        return;
    }

    int stack[end - start + 1];
    int top = -1;

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) {
        end = stack[top--];
        start = stack[top--];

        int pivot_index = partition_v3_0(arr, start, end);
        if (pivot_index - 1 > start) {
            stack[++top] = start;
            stack[++top] = pivot_index - 1;
        }

        if (pivot_index + 1 < end) {
            stack[++top] = pivot_index + 1;
            stack[++top] = end;
        }
    }
}

/**
 * Quick Sort (optimized v3.0)
 */
void *quick_sort_v3_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    __quick_sort_v3_0(arr, 0, n - 1);
    return arr;
}
