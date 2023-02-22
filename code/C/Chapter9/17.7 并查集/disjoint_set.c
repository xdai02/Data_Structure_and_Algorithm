#include <stdio.h>
#include <stdlib.h>

int *parent = NULL;     // 父结点数组
int *rank = NULL;       // 秩

/**
 * @brief  初始化每个元素的父结点
 * @note   初始时所有结点的父结点为自己本身
 * @param  n: 元素数量
 */
void init(int n) {
    parent = (int *)malloc(sizeof(int) * n);
    rank = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}

/**
 * @brief  查询一个元素所在集合的根结点
 * @param  val: 待查询元素
 * @retval 该集合根结点
 */
int find(int val) {
    if(parent[val] == val) {
        return val;
    } else {
        parent[val] = find(parent[val]);
        return parent[val];
    }
}

/**
 * @brief  合并两个集合
 * @param  i: 待合并元素1
 * @param  j: 待合并元素2
 */
void merge(int i, int j) {
    // 找到对应根结点
    int x = find(i);
    int y = find(j);
    if(rank[x] <= rank[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
    }
    // 如果深度相同且根结点不同，则新的根结点深度+1
    if(rank[x] == rank[y] && x != y) {
        rank[y]++;
    }
}

int main() {
    init(7);

    merge(3, 1);
    merge(2, 1);
    merge(5, 4);
    merge(6, 4);
    merge(4, 1);
    printf("%d\n", find(6));

    return 0;
}