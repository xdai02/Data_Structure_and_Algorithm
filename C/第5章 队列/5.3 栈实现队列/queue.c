#include "queue.h"

Queue* initQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->inStack = initStack(size);
    q->outStack = initStack(size);
    return q;
}

bool isEmptyQueue(Queue *q) {
    return isEmptyStack(q->inStack) && isEmptyStack(q->outStack);
}

void enqueue(Queue *q, dataType data) {
    push(q->inStack, data);
}

dataType dequeue(Queue *q) {
    if(isEmptyStack(q->outStack)) {
        while(!isEmptyStack(q->inStack)) {
            push(q->outStack, pop(q->inStack));
        }
    }
    return pop(q->outStack);
}

void deleteQueue(Queue *q) {
    deleteStack(q->inStack);
    deleteStack(q->outStack);
    free(q);
}