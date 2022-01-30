#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void radixSort(int *arr, int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // 创建桶
    int bucketNum = 10;
    Array *buckets[bucketNum];
    for(int i = 0; i < bucketNum; i++) {
        buckets[i] = initArray();
    }

    // 从个位开始
    for(int exp = 1; max / exp > 0; exp *= 10) {
        // 把元素放到对应桶中
        for(int i = 0; i < n; i++) {
            int num = (arr[i] / exp) % 10;
            append(buckets[num], arr[i]);
        }

        // 按顺序取出元素
        int cnt = 0;
        for(int i = 0; i < bucketNum; i++) {
            for(int j = 0; j < buckets[i]->size; j++) {
                arr[cnt++] = buckets[i]->data[j];
            }
            clearArray(buckets[i]);
        }
    }

    for(int i = 0; i < bucketNum; i++) {
        deleteArray(buckets[i]);
    }
}

int main() {
    int arr[] = {63, 157, 189, 51, 101, 47, 141, 121, 157, 156,
                 194, 117, 98, 139, 67, 133, 181, 12, 28, 0, 109};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    showArr(arr, n);
    return 0;
}