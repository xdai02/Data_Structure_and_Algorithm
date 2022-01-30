#include <stdio.h>
#include <stdbool.h>

void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

/**
 * @brief  打印数组
 * @param  arr: 数组
 * @param  n: 数组长度
 */
void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief  冒泡排序
 * @param  arr: 数组
 * @param  n: 数组长度
 */
void bubbleSort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void bubbleSortOptimize1(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        bool isSorted = false;  // 标记是否发生交换
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSorted = true;    // 发生交换
            }
        }
        // 该轮未发生交换，已经有序
        if(!isSorted) {
            return;
        }
    }
}

void bubbleSortOptimize2(int *arr, int n) {
    int len = n - 1;        // 内层循环执行次数
    for(int i = 0; i < n - 1; i++) {
        bool isSorted = false;  // 标记是否发生交换
        int last = 0;       // 标记最后一次发生交换的位置
        for(int j = 0; j < len; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSorted = true;    // 发生交换
                last = j;
            }
        }
        // 该轮未发生交换，已经有序
        if(!isSorted) {
            return;
        }
        len = last;         // 最后一次发生交换的位置
    }
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前：");
    showArr(arr, n);
    
    // 未优化
    bubbleSort(arr, n);
    // 第一次优化
    // bubbleSortOptimize1(arr, n);
    // 第二次优化
    // bubbleSortOptimize2(arr, n);

    printf("排序后：");
    showArr(arr, n);
    return 0;
}