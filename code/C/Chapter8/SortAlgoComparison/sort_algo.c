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

const int INSERTION_SORT_THRESHOLD = 10;

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
    memcpy(left_half, arr, mid * sizeof(T));
    memcpy(right_half, arr + mid, (n - mid) * sizeof(T));

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

    if (n <= INSERTION_SORT_THRESHOLD) {
        return insertion_sort_v2_0(args);
    }

    int mid = n / 2;
    T left_half[mid];
    T right_half[n - mid];
    memcpy(left_half, arr, mid * sizeof(T));
    memcpy(right_half, arr + mid, (n - mid) * sizeof(T));

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
static void merge(T *arr, int start, int mid, int end) {
    if (end - start + 1 <= INSERTION_SORT_THRESHOLD) {
        T temp[end - start + 1];
        memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
        argument_t arg = {temp, end - start + 1};
        insertion_sort_v2_0(&arg);
        memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
        return;
    }

    int n1 = mid - start + 1;
    int n2 = end - mid;

    T left_half[n1];
    T right_half[n2];
    memcpy(left_half, arr + start, n1 * sizeof(T));
    memcpy(right_half, arr + mid + 1, n2 * sizeof(T));

    int i = 0;
    int j = 0;
    int k = start;

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

    int current_size = 1;
    while (current_size < n - 1) {
        int start = 0;
        while (start < n - 1) {
            int mid = min(start + current_size - 1, n - 1);
            int end = min(start + 2 * current_size - 1, n - 1);
            merge(arr, start, mid, end);
            start = end + 1;
        }
        current_size *= 2;
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
static void __quick_sort_v1_0(T *arr, int start, int end) {
    if (start < end) {
        T pivot = arr[start];

        int pivot_index = partition(arr, start, end, pivot);
        __quick_sort_v1_0(arr, start, pivot_index - 1);
        __quick_sort_v1_0(arr, pivot_index + 1, end);
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
 * Help function for Quick Sort (optimized v2.0)
 */
static void __quick_sort_v2_0(T *arr, int start, int end) {
    if (start < end) {
        int pivot_index = rand() % (end - start + 1) + start;
        swap(arr[start], arr[pivot_index]);
        T pivot = arr[start];

        pivot_index = partition(arr, start, end, pivot);
        __quick_sort_v2_0(arr, start, pivot_index - 1);
        __quick_sort_v2_0(arr, pivot_index + 1, end);
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
 * Help function for Quick Sort (optimized v2.1)
 */
static void __quick_sort_v2_1(T *arr, int start, int end) {
    if (start < end) {
        int pivot_index = median_of_three(arr, start, end);
        swap(arr[start], arr[pivot_index]);
        T pivot = arr[start];

        pivot_index = partition(arr, start, end, pivot);
        __quick_sort_v2_1(arr, start, pivot_index - 1);
        __quick_sort_v2_1(arr, pivot_index + 1, end);
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
 * Help function for Quick Sort (optimized v2.2)
 */
static void __quick_sort_v2_2(T *arr, int start, int end) {
    if (end - start <= INSERTION_SORT_THRESHOLD) {
        T temp[end - start + 1];
        memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
        argument_t arg = {temp, end - start + 1};
        insertion_sort_v2_0(&arg);
        memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
        return;
    }

    int pivot_index = median_of_three(arr, start, end);
    swap(arr[start], arr[pivot_index]);
    T pivot = arr[start];

    pivot_index = partition(arr, start, end, pivot);
    __quick_sort_v2_2(arr, start, pivot_index - 1);
    __quick_sort_v2_2(arr, pivot_index + 1, end);
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
 * Help function for Quick Sort (optimized v3.0)
 */
static void __quick_sort_v3_0(T *arr, int start, int end) {
    int stack[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) {
        end = stack[top--];
        start = stack[top--];

        if (end - start + 1 <= INSERTION_SORT_THRESHOLD) {
            T temp[end - start + 1];
            memcpy(temp, arr + start, sizeof(T) * (end - start + 1));
            argument_t arg = {temp, end - start + 1};
            insertion_sort_v2_0(&arg);
            memcpy(arr + start, temp, sizeof(T) * (end - start + 1));
            continue;
        }

        int pivot_index = median_of_three(arr, start, end);
        int pivot = arr[pivot_index];
        int i = start, j = end - 1;
        swap(arr[pivot_index], arr[end]);

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        swap(arr[i], arr[end]);

        if (i - start < end - i) {
            stack[++top] = start;
            stack[++top] = i - 1;
            stack[++top] = i + 1;
            stack[++top] = end;
        } else {
            stack[++top] = i + 1;
            stack[++top] = end;
            stack[++top] = start;
            stack[++top] = i - 1;
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

/**
 * Helper function for Heap Sort (original v1.0)
 */
static void heapify(T *arr, int index, int n) {
    int child_index = 2 * index + 1;
    while (child_index < n) {
        if (child_index + 1 < n && arr[child_index + 1] > arr[child_index]) {
            child_index++;
        }
        if (arr[index] >= arr[child_index]) {
            break;
        }
        swap(arr[index], arr[child_index]);
        index = child_index;
        child_index = 2 * index + 1;
    }
}

/**
 * Heap Sort (original v1.0)
 */
void *heap_sort_v1_0(void *args) {
    argument_t *arg = (argument_t *)args;
    T *arr = arg->data;
    int n = arg->n;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

    return arr;
}