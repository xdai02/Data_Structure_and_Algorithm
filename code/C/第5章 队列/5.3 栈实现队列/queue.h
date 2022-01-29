#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef int dataType;

typedef struct Queue {
    Stack *inStack;
    Stack *outStack;
} Queue;

Queue* initQueue(int size);

bool isEmptyQueue(Queue *q);

void enqueue(Queue *q, dataType data);

dataType dequeue(Queue *q);

void deleteQueue(Queue *q);

#endif