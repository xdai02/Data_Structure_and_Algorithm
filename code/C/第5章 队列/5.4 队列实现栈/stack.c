#include "stack.h"

Stack* initStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->queue = initQueue(size);
    return s;
}

bool isEmptyStack(Stack *s) {
    return isEmptyQueue(s->queue);
}

void push(Stack *s, dataType data) {
    int n = s->queue->size;
    enqueue(s->queue, data);
    for(int i = 0; i < n; i++) {
        enqueue(s->queue, dequeue(s->queue));
    }
}

dataType pop(Stack *s) {
    return dequeue(s->queue);
}

dataType peek(Stack *s) {
    return s->queue->data[0];
}

void deleteStack(Stack *s) {
    deleteQueue(s->queue);
    free(s);
}