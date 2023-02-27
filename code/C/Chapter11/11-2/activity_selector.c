#include <stdio.h>
#include <stdlib.h>

int* selectActivity(int *a, int aSize, 
               int *s, int sSize, 
               int *f, int fSize, int *activityCnt) {
    int *activity = (int *)malloc(sizeof(int) * aSize);
    if(!activity) {
        return NULL;
    }

    *activityCnt = 0;
    activity[(*activityCnt)++] = a[0];
    int k = 0;
    for(int i = 1; i < sSize; i++) {
        if(s[i] >= f[k]) {
            activity[(*activityCnt)++] = a[i];
            k = i;
        }
    }

    return activity;
}

int main() {
    // 活动集合
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int aSize = sizeof(a) / sizeof(a[0]);
    // 活动开始时间集合
    int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int sSize = sizeof(s) / sizeof(s[0]);
    // 活动结束时间集合
    int f[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int fSize = sizeof(f) / sizeof(f[0]);

    int cnt = 0;        // 选择的活动数量
    int *activity = selectActivity(a, aSize, s, sSize, f, fSize, &cnt);
    if(activity) {
        printf("选择活动：");
        for(int i = 0; i < cnt; i++) {
            printf("%d ", activity[i]);
        }
        printf("\n");
        free(activity);
    }

    return 0;
}