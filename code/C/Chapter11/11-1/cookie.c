#include <stdio.h>
#include <stdlib.h>

int cmp(const void *_a, const void *_b) {
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *a - *b;
}

int distribute(int *children, int childrenSize,
               int *cookies, int cookiesSize) {
    qsort(children, childrenSize, sizeof(children[0]), cmp);
    qsort(cookies, cookiesSize, sizeof(cookies[0]), cmp);
    int child = 0;
    int cookie = 0;
    while (child < childrenSize && cookie < cookiesSize) {
        if (children[child] <= cookies[cookie++]) {
            child++;
        }
    }
    return child;
}

int main() {
    int children[] = {1, 2};
    int childrenSize = sizeof(children) / sizeof(children[0]);
    int cookies[] = {1, 2, 3};
    int cookiesSize = sizeof(cookies) / sizeof(cookies[0]);
    printf("%d\n", distribute(children, childrenSize, 
                              cookies, cookiesSize));
    return 0;
}