#include <stdio.h>
#include "queue.h"

int main() {
    Queue *q = initQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    while(!isEmptyQueue(q)) {
        printf("%d\n", dequeue(q));
    }
    deleteQueue(q);

    return 0;
}