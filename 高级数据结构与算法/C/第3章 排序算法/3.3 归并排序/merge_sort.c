#include <stdio.h>

void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void binaryInsertionSort(int *arr, int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int start = left;
        int end = i - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] > temp) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        int j;
        for(j = i - 1; j > end; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

void merge(int *arr, int start, int mid, int end, int *temp) {
    int i = start;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }

    for(int i = 0; i < k; i++) {
        arr[start+i] = temp[i];
    }
}

void mergeSortWorker(int *arr, int start, int end, int *temp) {
    // 列表长度小于10时，采用二分插入排序
    if(end - start <= 10) {
        binaryInsertionSort(arr, start, end);
        return;
    }
    if(start < end) {
        int mid = start + (end - start) / 2;
        mergeSortWorker(arr, start, mid, temp);
        mergeSortWorker(arr, mid+1, end, temp);
        // 避免不必要的合并
        if(arr[mid] <= arr[mid+1]) {
            return;
        }
        merge(arr, start, mid, end, temp);
    }
}

void mergeSort(int *arr, int n) {
    int temp[n];        // 临时数组
    mergeSortWorker(arr, 0, n-1, temp);
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    showArr(arr, n);
    return 0;
}