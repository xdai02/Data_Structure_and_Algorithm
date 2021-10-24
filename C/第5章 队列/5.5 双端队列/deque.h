#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Node {
    dataType data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Deque;

Deque* initDeque();

bool isEmptyDeque(Deque *deque);

void addFront(Deque *deque, dataType val);

void addRear(Deque *deque, dataType val);

dataType removeFront(Deque *deque);

dataType removeRear(Deque *deque);

dataType getFront(Deque *deque);

dataType getRear(Deque *deque);

void deleteDeque(Deque *deque);

#endif