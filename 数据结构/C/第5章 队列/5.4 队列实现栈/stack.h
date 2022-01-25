#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

typedef int dataType;

typedef struct Stack {
    Queue *queue;
} Stack;

Stack* initStack(int size);

bool isEmptyStack(Stack *s);

void push(Stack *s, dataType val);

dataType pop(Stack *s);

dataType peek(Stack *s);

void deleteStack(Stack *s);

#endif