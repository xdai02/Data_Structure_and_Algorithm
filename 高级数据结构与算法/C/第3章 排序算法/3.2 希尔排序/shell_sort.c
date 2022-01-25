#include <stdio.h>
#include <stdlib.h>

void showArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief  希尔排序（Shell增量序列）
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
 * @brief  逆序数组
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
 */
void reverse(int *arr, int n) {
    int i = 0;
    int j = n - 1;
    while(i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

/**
 * @brief  生成Hibbard序列
 * @note   1, 3, 7, 15, 31, 63, ...
 * @param  n: 不大于n的序列
 * @retval Hibbard序列
 */
int* getHibbardSequence(int n, int *cnt) {
    int size = 10;      // 序列初始容量
    int *sequence = (int *)malloc(sizeof(int) * size);
    *cnt = 0;           // 记录序列长度

    int i = 1;
    while(i <= n) {
        // 扩容
        if(*cnt >= size) {
            size *= 2;
            sequence = (int *)realloc(sequence, sizeof(int) * size);
        }
        sequence[(*cnt)++] = i;
        i = (i << 1) + 1;
    }

    // 收缩
    if(*cnt < size) {
        sequence = (int *)realloc(sequence, sizeof(int) * (*cnt));
    }

    reverse(sequence, *cnt);
    return sequence;
}

/**
 * @brief  希尔排序（Hibbard增量序列）
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
 */
void shellSortHibbard(int *arr, int n) {
    int len = 0;
    int *hibbard = getHibbardSequence(n, &len);
    
    for(int i = 0; i < len; i++) {
        int gap = hibbard[i];
        for(int j = gap; j < n; j++) {
            int k = j;
            int temp = arr[k];
            while(k >= gap) {
                if(temp < arr[k-gap]) {
                    arr[k] = arr[k-gap];
                    k -= gap;
                } else {
                    break;
                }
            }
            arr[k] = temp;
        }
    }

    free(hibbard);
}

/**
 * @brief  生成Sedgewick序列
 * @note   1, 5, 19, 41, 109, ...
 * @param  n: 不大于n的序列
 * @retval Sedgewick序列
 */
int* getSedgewickSequence(int n, int *cnt) {
    int size = 10;      // 序列初始容量
    int *sequence = (int *)malloc(sizeof(int) * size);
    *cnt = 0;           // 记录序列长度

    int i = 0;
    while(1) {
        // 扩容
        if(*cnt >= size) {
            size *= 2;
            sequence = (int *)realloc(sequence, sizeof(int) * size);
        }

        // 9 * 4^i - 9 * 2^i + 1 ==> 9 * (2^(2*i) - 2^i) + 1
        int item = 9 * ((1 << (2 * i)) - (1 << i)) + 1;
        if(item <= n) {
            sequence[(*cnt)++] = item;
        } else {
            break;
        }

        // 4^(i+2) - 3 * 2^(i+2) + 1 ==> 2^(2i+4) - 3 * 2^(i+2) + 1
        item = (1 << (2 * i + 4)) - 3 * (1 << (i + 2)) + 1;
        if(item <= n) {
            sequence[(*cnt)++] = item;
        } else {
            break;
        }

        i++;
    }

    // 收缩
    if(*cnt < size) {
        sequence = (int *)realloc(sequence, sizeof(int) * (*cnt));
    }

    reverse(sequence, *cnt);
    return sequence;
}

/**
 * @brief  希尔排序（Sedgewick增量序列）
 * @param  arr: 数组
 * @param  n: 数组长度
 * @retval None
 */
void shellSortSedgewick(int *arr, int n) {
    int len = 0;
    int *sedgewick = getSedgewickSequence(n, &len);
    
    for(int i = 0; i < len; i++) {
        int gap = sedgewick[i];
        for(int j = gap; j < n; j++) {
            int k = j;
            int temp = arr[k];
            while(k >= gap) {
                if(temp < arr[k-gap]) {
                    arr[k] = arr[k-gap];
                    k -= gap;
                } else {
                    break;
                }
            }
            arr[k] = temp;
        }
    }

    free(sedgewick);
}

int main() {
    int arr[] = {5, 8, 6, 3, 9, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 希尔排序
    shellSort(arr, n);

    // Hibbard增量序列
    // shellSortHibbard(arr, n);

    // Sedgewick增量序列
    // shellSortSedgewick(arr, n);

    showArr(arr, n);
    return 0;
}