#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *p1, const void *p2) {
    int *num1 = (int *)p1;
    int *num2 = (int *)p2;
    return *num1 - *num2;
}

int distribute(int *children, int children_num, int *cookies, int cookies_num) {
    qsort(children, children_num, sizeof(children[0]), cmp);
    qsort(cookies, cookies_num, sizeof(cookies[0]), cmp);

    int child = 0;
    int cookie = 0;
    while (child < children_num && cookie < cookies_num) {
        if (children[child] <= cookies[cookie]) {
            child++;
        }
        cookie++;
    }
    return child;
}

int main() {
    int children[] = {1, 2};
    int children_num = sizeof(children) / sizeof(children[0]);
    int cookies[] = {1, 2, 3};
    int cookies_num = sizeof(cookies) / sizeof(cookies[0]);

    printf("%d\n", distribute(children, children_num, cookies, cookies_num));
    return 0;
}