#include <stdio.h>

/**
 * @brief  二分查找
 * @param  arr: 待查找数组
 * @param  n: 数组长度
 * @param  key: 关键字
 * @retval 关键字下标，不存在返回-1
 */
int binarySearch(int *arr, int n, int key) {
    int start = 0;
    int end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {7, 9, 20, 34, 40, 85, 91, 93};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 34;
    printf("%d所在位置：%d\n", key, binarySearch(arr, n, key));
    return 0;
}