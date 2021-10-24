#include <stdio.h>
#include "stack.h"

int main() {
    Stack *s = initStack(5);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    while(!isEmptyStack(s)) {
        printf("%d\n", pop(s));
    }

    return 0;
}