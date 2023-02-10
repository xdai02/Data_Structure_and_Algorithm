/**
 * 对比不同算法对data.txt中50000个整数进行排序的时间
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 50000

char *filename = "data.txt";    // 数据文件

/**
 * @brief  从文件读取数据
 * @param  filename: 数据文件
 * @param  arr: 保存数据的数组
 * @retval 成功返回true，失败返回false
 * */
bool readData(const char *filename, int *arr) {
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        fprintf(stderr, "File Open Failed\n");
        return false;
    }

    // 从文件读取50000个数据
    for(int i = 0; i < MAX; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    return true;
}

/**
 * @brief  排序结果保存到文件
 * @param  filename: 文件名
 * @param  arr: 排序后数组
 * @param  n: 数组长度
 * @retval 成功返回true，失败返回false
 */
bool saveFile(const char *filename, int *arr, int n) {
    FILE *fp = fopen(filename, "w");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
    return true;
}

void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

/**
 * @brief  冒泡排序
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
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

/**
 * @brief  选择排序
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
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

/**
 * @brief  插入排序
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
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

/**
 * @brief  希尔排序
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
 */
void shellSort(int *arr, int n) {
    int gap = n;
    while(gap > 1) {
        gap /= 2;
        for(int i = 0; i < gap; i++) {
            for(int j = i+gap; j < n; j += gap) {
                int temp = arr[j];
                int k = j - gap;
                while(k >= 0 && arr[k] > temp) {
                    arr[k+gap] = arr[k];
                    k -= gap;
                }
                arr[k+gap] = temp;
            }
        }
    }    
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
    int arr[MAX];                   // 保存数据的数组
    int temp[MAX];                  // 归并排序需要使用的临时数组
    clock_t start, end;             // 记录开始、结束时间
    double running_time = 0.0;      // 排序时间

    /*************** 【冒泡排序】 ***************/
    printf("开始【冒泡排序】...\n");
    readData(filename, arr);
    start = clock();
    bubbleSort(arr, MAX);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【冒泡排序】：%.3f秒\n", running_time);
    saveFile("bubbleSort.txt", arr, MAX);

    /*************** 【选择排序】 ***************/
    printf("开始【选择排序】...\n");
    readData(filename, arr);
    start = clock();
    selectionSort(arr, MAX);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【选择排序】：%.3f秒\n", running_time);
    saveFile("selectionSort.txt", arr, MAX);

    /*************** 【插入排序】 ***************/
    printf("开始【插入排序】...\n");
    readData(filename, arr);
    start = clock();
    insertionSort(arr, MAX);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【插入排序】：%.3f秒\n", running_time);
    saveFile("insertionSort.txt", arr, MAX);

    /*************** 【希尔排序】 ***************/
    printf("开始【希尔排序】...\n");
    readData(filename, arr);
    start = clock();
    shellSort(arr, MAX);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【希尔排序】：%.3f秒\n", running_time);
    saveFile("shellSort.txt", arr, MAX);

    /*************** 【归并排序】 ***************/
    printf("开始【归并排序】...\n");
    readData(filename, arr);
    start = clock();
    mergeSort(arr, 0, MAX-1, temp);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【归并排序】：%.3f秒\n", running_time);
    saveFile("mergeSort.txt", arr, MAX);

    /*************** 【快速排序】 ***************/
    printf("开始【快速排序】...\n");
    readData(filename, arr);
    start = clock();
    quickSort(arr, 0, MAX-1);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【快速排序】：%.3f秒\n", running_time);
    saveFile("quickSort.txt", arr, MAX);

    /*************** 【堆排序】 ***************/
    printf("开始【堆排序】...\n");
    readData(filename, arr);
    start = clock();
    heapSort(arr, MAX);
    end = clock();
    running_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\t【堆排序】：%.3f秒\n", running_time);
    saveFile("heapSort.txt", arr, MAX);

    return 0;
}