#include <stdio.h>

int move = 0;       // 移动次数

/**
 * @brief  汉诺塔算法
 * @note   把 n 个盘子从 src 借助 mid 移到 dst
 * @param  n: 层数
 * @param  src: 起点柱子
 * @param  mid: 临时柱子
 * @param  dst: 目标柱子
 */
void hanoi(int n, char src, char mid, char dst) {
    if(n == 1) {
        printf("%d号盘：%c -> %c\n", n, src, dst);
        move++;
    } else {
        // 把前 n-1 个盘子从 src 借助 dst 移到 mid
        hanoi(n-1, src, dst, mid);
        // 移动第 n 个盘子
        printf("%d号盘：%c -> %c\n", n, src, dst);
        move++;
        // 把刚才的 n-1 个盘子从 mid 借助 src 移到 dst
        hanoi(n-1, mid, src, dst);
    }
}

int main() {
    hanoi(4, 'A', 'B', 'C');
    printf("步数 ==> %d\n", move);
    return 0;
}