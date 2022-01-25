/**
 * （鸡兔同笼）
 * 上有三十五头，下有九十四足，问鸡兔各几何？
 */
#include <stdio.h>

/**
 * @brief  鸡兔同笼
 * @param  head: 头数
 * @param  foot: 脚数
 * @retval None
 */
void count(int head, int foot) {
    for(int chicken = 0; chicken <= head; chicken++) {
        int rabbit = head - chicken;
        if(chicken*2 + rabbit*4 == foot) {
            printf("鸡：%2d\t兔：%2d\n", chicken, rabbit);
        }
    }
}

int main() {
    count(35, 94);
    return 0;
}