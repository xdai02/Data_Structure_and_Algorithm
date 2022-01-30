#include <stdio.h>

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
 * @brief  快速排序
 * @param  arr: 待排序数组
 * @param  start: 开始下标
 * @param  end: 结束下标
 * @retval None
 */
void quickSort(int *arr, int start, int end) {
    if(start < end) {
        int i = start;
        int j = end;
        int pivot = arr[start];

        while(i < j) {
            while(i < j && arr[j] > pivot) {
                j--;
            }
            if(i < j) {
                arr[i] = arr[j];
                i++;
            }
            while(i < j && arr[i] < pivot) {
                i++;
            }
            if(i < j) {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = pivot;
        quickSort(arr, start, i-1);
        quickSort(arr, i+1, end);
    } 
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前：");
    showArr(arr, n);
    quickSort(arr, 0, n-1);
    printf("排序后：");
    showArr(arr, n);
    return 0;
}