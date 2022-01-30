#include <stdio.h>
#include <stdlib.h>
#define MAX 50000       // 50000个整数数据

/**
 * @brief  统计数组中逆序对数
 * @param  arr: 数组
 * @param  n: 数组带下
 * @retval 逆序对数
 */
int countInversions(int *arr, int n) {
    int cnt = 0;        // 逆序对数
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if(!fp) {
        fprintf(stderr, "File Open Failed\n");
        exit(1);
    }

    // 从文件中读取数据
    int arr[MAX];
    for(int i = 0; i < MAX; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    printf("逆序对数：%d\n", countInversions(arr, MAX));
    fclose(fp);
    return 0;
}