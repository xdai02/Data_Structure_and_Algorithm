#include "stack.h"

Stack* initStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(!s) {
        return NULL;
    }
    s->data = (dataType *)malloc(size * sizeof(dataType));
    if(!s->data) {
        free(s);
        return NULL;
    }
    s->top = -1;
    s->capacity = size;
    return s;
}

bool isFullStack(Stack *s) {
    return s->top == s->capacity - 1;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, dataType data) {
    if(isFullStack(s)) {
        s->data = (dataType *)realloc(s->data, s->capacity * 2 * (sizeof(dataType)));
        if(!s->data) {
            return;
        }
    }
    s->data[++s->top] = data;
}

dataType pop(Stack *s) {
    return s->data[s->top--];
}

dataType peek(Stack *s) {
    return s->data[s->top];
}

void deleteStack(Stack *s) {
    if(s) {
        if(s->data) {
            free(s->data);
            s->data = NULL;
        }
        free(s);
        s = NULL;
    }
}