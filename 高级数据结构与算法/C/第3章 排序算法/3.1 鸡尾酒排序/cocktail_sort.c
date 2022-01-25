#include <stdio.h>
#include <stdbool.h>

void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void showArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void cocktailSort1(int *arr, int n) {
    for(int i = 0; i < n / 2; i++) {
        // 从左向右
        bool isSorted = true;   // 标记当前轮是否有序
        for(int j = i; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSorted = false;   // 发生交换
            }
        }
        if(isSorted) {
            break;
        }

        // 从右向左
        isSorted = true;
        for(int j = n - i - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
                isSorted = false;
            }
        }
        if(isSorted) {
            break;
        }
    }
}

void cocktailSort2(int *arr, int n) {
    int lastLeft = 0;           // 左侧最后一次交换位置
    int lastRight = 0;          // 右侧最后一次交换位置
    int leftBorder = 0;         // 无序区左边界
    int rightBorder = n - 1;    // 无序区右边界

    for(int i = 0; i < n / 2; i++) {
        // 从左向右
        bool isSorted = true;   // 标记当前轮是否有序
        for(int j = leftBorder; j < rightBorder; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSorted = false;   // 发生交换
                lastRight = j;
            }
        }
        if(isSorted) {
            break;
        }
        rightBorder = lastRight;

        // 从右向左
        isSorted = true;
        for(int j = n - i - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
                isSorted = false;
                lastLeft = j;
            }
        }
        if(isSorted) {
            break;
        }
        leftBorder = lastLeft;
    }
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int n = sizeof(arr) / sizeof(int);

    // 未优化
    cocktailSort1(arr, n);

    // 优化
    // cocktailSort2(arr, n);

    showArray(arr, n);

    return 0;
}