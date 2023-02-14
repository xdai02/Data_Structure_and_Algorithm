#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
T *bucket_sort(T *arr, int n) {
    if (n == 0) {
        return arr;
    }

    T max_val = *max_element(arr, arr + n);
    T min_val = *min_element(arr, arr + n);
    int bucket_size = (max_val - min_val) / n + 1;

    vector<vector<T>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min_val) / bucket_size;
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int i = 0;
    for (int j = 0; j < n; j++) {
        for (T elem : buckets[j]) {
            arr[i++] = elem;
        }
    }

    return arr;
}

int main() {
    int arr[] = {18, 11, 28, 45, 23, 49};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}