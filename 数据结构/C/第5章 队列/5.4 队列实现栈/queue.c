#include "queue.h"

Queue* initQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (dataType *)malloc(sizeof(dataType) * (capacity + 1));
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

bool isEmptyQueue(Queue *q) {
    return q->size == 0;
}

bool isFullQueue(Queue *q) {
    return q->size == q->capacity;
}

void enqueue(Queue *q, dataType data) {
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

dataType dequeue(Queue *q) {
    dataType val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

void deleteQueue(Queue *q) {
    free(q->data);
    free(q);
}