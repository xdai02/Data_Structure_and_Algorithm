#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Stack {
    dataType *data;
    int top;
    int capacity;
} Stack;

Stack* initStack(int size);

bool isFullStack(Stack *s);

bool isEmptyStack(Stack *s);

void push(Stack *s, dataType data);

dataType pop(Stack *s);

dataType peek(Stack *s);

void deleteStack(Stack *s);

#endif