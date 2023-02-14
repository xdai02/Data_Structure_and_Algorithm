#include <iostream>
#include <algorithm>

using namespace std;

int *counting_sort(int *arr, int n) {
    if(n == 0) {
        return arr;
    }

    int max_val = *max_element(arr, arr + n);
    int min_val = *min_element(arr, arr + n);

    int range = max_val - min_val + 1;
    int *counts = new int[range];
    if (!counts) {
        exit(1);
    }
    for (int i = 0; i < range; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        counts[arr[i] - min_val]++;
    }

    int cnt = 0;
    for (int i = 0; i < range; i++) {
        while (counts[i]--) {
            arr[cnt] = i + min_val;
            cnt++;
        }
    }

    delete[] counts;
    return arr;
}

int main() {
    int arr[] = {95, 94, 91, 98, 99, 90, 99, 93, 91, 92};
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}