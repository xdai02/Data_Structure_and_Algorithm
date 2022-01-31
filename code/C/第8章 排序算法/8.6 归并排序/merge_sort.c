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
 * @brief  合并
 * @param  arr: 待排序数组
 * @param  start: 开始下标
 * @param  mid: 中间下标
 * @param  end: 结束下标
 * @param  temp: 临时数组
 * @retval None
 */
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

/**
 * @brief  归并排序
 * @param  arr: 待排序数组
 * @param  start: 开始下标
 * @param  end: 结束下标
 * @param  temp: 临时数组
 * @retval None
 */
void mergeSort(int *arr, int start, int end, int *temp) {
    if(start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid, temp);
        mergeSort(arr, mid+1, end, temp);
        merge(arr, start, mid, end, temp);
    }
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];        // 临时数组
    
    printf("排序前：");
    showArr(arr, n);
    mergeSort(arr, 0, n-1, temp);
    printf("排序后：");
    showArr(arr, n);
    return 0;
}