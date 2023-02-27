#include <iostream>

using namespace std;

template <typename T>
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
template <typename T>
T *heap_sort(T *arr, int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

    return arr;
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 7, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}