#include <stdio.h>

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
 * @brief  下沉调整
 * @param  arr: 待调整的堆
 * @param  parentIndex: 要下沉的父结点
 * @param  length: 堆的有效大小
 */
void downAdjust(int *arr, int parentIndex, int length) {
    // 保存父结点的值，用于最后的赋值
    int temp = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;

    while(childIndex < length) {
        // 如果有右孩子，且右孩子大于左孩子的值，则定位到右孩子
        if(childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
            childIndex++;
        }
        // 如果父结点小于任何一个孩子的值，直接跳出
        if(temp >= arr[childIndex]) {
            break;
        }
        // 无需真正交换，单向赋值即可
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    arr[parentIndex] = temp;
}

/**
 * @brief  堆排序
 * @param  arr: 待调整的堆
 * @param  n: 数组大小
 */
void heapSort(int *arr, int n) {
    // 把无序数组构建成二叉堆
    for(int i = (n-2) / 2; i >= 0; i--) {
        downAdjust(arr, i, n);
    }

    // 循环删除堆顶元素，移到数组尾部，调节堆产生新的堆顶
    for(int i = n - 1; i > 0; i--) {
        // 最后一个元素和第一个元素交换
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        // 下沉调整最大堆
        downAdjust(arr, 0, i);
    }
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前：");
    showArr(arr, n);
    heapSort(arr, n);
    printf("排序后：");
    showArr(arr, n);

    return 0;
}