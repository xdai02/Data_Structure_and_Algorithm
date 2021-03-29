#include <stdio.h>

/**
 * @brief  顺序查找
 * @param  arr: 待查找数组
 * @param  n: 数组长度
 * @param  key: 关键字
 * @retval 关键字下标，不存在返回-1
 */
int sequenceSearch(int *arr, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {40, 9, 20, 93, 7, 34, 85, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 34;
    printf("%d所在位置：%d\n", key, sequenceSearch(arr, n, key));
    return 0;
}