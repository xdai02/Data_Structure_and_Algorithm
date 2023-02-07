#include <iostream>

using namespace std;

template <typename T>
int sequence_search(T *arr, int n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {40, 9, 20, 93, 7, 34, 85, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 34;
    cout << "index = " << sequence_search(arr, n, key) << endl;
    return 0;
}