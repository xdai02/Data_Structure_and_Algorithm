#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int n) {
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    int diff = max - min + 1;
    
    // 创建桶
    int bucketNum = n;
    Array *buckets[bucketNum];
    for(int i = 0; i < bucketNum; i++) {
        buckets[i] = initArray();
    }

    // 遍历列表，把元素放入对应桶中
    for(int i = 0; i < n; i++) {
        // 计算当前元素所放置的桶号
        int num = (arr[i] - min) / (diff / (bucketNum - 1));
        append(buckets[num], arr[i]);
    }

    // 桶内排序
    for(int i = 0; i < bucketNum; i++) {
        qsort(buckets[i]->data, buckets[i]->size,
              sizeof(buckets[i]->data[0]), cmp);
    }
    
    // 取出元素
    int cnt = 0;
    for(int i = 0; i < bucketNum; i++) {
        for(int j = 0; j < buckets[i]->size; j++) {
            arr[cnt++] = buckets[i]->data[j];
        }
    }

    for(int i = 0; i < bucketNum; i++) {
        deleteArray(buckets[i]);
    }
}

int main() {
    int arr[] = {4, 6, 23, 3, 21, 8, 41, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    showArr(arr, n);
    return 0;
}