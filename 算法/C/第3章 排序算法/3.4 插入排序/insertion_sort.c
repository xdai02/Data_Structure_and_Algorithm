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
 * @brief  插入排序
 * @param  arr: 数组
 * @param  n: 数组长度
 */
void insertionSort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void binaryInsertionSort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int start = 0;
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

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前：");
    showArr(arr, n);
	
	// 未优化
    insertionSort(arr, n);
	// 优化
	// binaryInsertionSort(arr, n);
	
    printf("排序后：");
    showArr(arr, n);
    return 0;
}