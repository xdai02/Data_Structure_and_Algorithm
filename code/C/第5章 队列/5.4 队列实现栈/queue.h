#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Queue {
    dataType *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* initQueue(int capacity);

bool isEmptyQueue(Queue *q);

bool isFullQueue(Queue *q);

void enqueue(Queue *q, dataType data);

dataType dequeue(Queue *q);

void deleteQueue(Queue *q);

#endif