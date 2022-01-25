#include <stdio.h>

void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

/**
 * @brief  打印数组
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
 */
void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief  选择排序
 * @param  arr: 数组
 * @param  n: 数组长度
 */
void selectionSort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(i != minIndex) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void selectionSortOptimize(int *arr, int n) {
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int min = left;
        int max = right;
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[min]) {
                min = i;
            }
            if(arr[i] > arr[max]) {
                max = i;
            }
        }
        swap(&arr[max], &arr[right]);
        // 考虑特殊情况，最小值在最右位置
        if(min == right) {
            min = max;
        }
        swap(&arr[min], &arr[left]);
        left++;
        right--;
    }
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前：");
    showArr(arr, n);

    // 未优化
    selectionSort(arr, n);
    // 优化
    // selectionSortOptimize(arr, n);

    printf("排序后：");
    showArr(arr, n);
    return 0;
}