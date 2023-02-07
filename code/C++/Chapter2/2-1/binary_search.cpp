#include <iostream>

using namespace std;

template <typename T>
int binary_search(T *arr, int n, T key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {7, 9, 20, 34, 40, 85, 91, 93};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 34;
    cout << "index = " << binary_search(arr, n, key) << endl;
    return 0;
}