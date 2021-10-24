#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;
    int top;
} Stack;

typedef struct {
    Stack *stack;
    Stack *minStack;
} MinStack;

int min(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
}

MinStack* init(int size) {
    MinStack *minStack = (MinStack *)malloc(sizeof(MinStack));

    minStack->stack = (Stack *)malloc(sizeof(Stack));
    minStack->stack->data = (int *)malloc(sizeof(int) * size);
    minStack->stack->top = -1;

    minStack->minStack = (Stack *)malloc(sizeof(Stack));
    minStack->minStack->data = (int *)malloc(sizeof(int) * size);
    minStack->minStack->data[0] = INT_MAX;
    minStack->minStack->top = 0;

    return minStack;
}

void push(MinStack *minStack, int data) {
    minStack->stack->data[++minStack->stack->top] = data;
    minStack->minStack->data[++minStack->minStack->top] = min(data, minStack->minStack->data[minStack->minStack->top]);
}

void pop(MinStack *minStack) {
    minStack->stack->top--;
    minStack->minStack->top--;
}

int peek(MinStack *minStack) {
    return minStack->stack->data[minStack->stack->top];
}

int getMin(MinStack *minStack) {
    return minStack->minStack->data[minStack->minStack->top];
}

void deleteMinStack(MinStack *minStack) {
    free(minStack->stack->data);
    free(minStack->stack);
    free(minStack->minStack->data);
    free(minStack->minStack);
    free(minStack);
}

int main() {
    MinStack *minStack = init(5);

    push(minStack, -2);
    push(minStack, 0);
    push(minStack, -3);

    printf("%d\n", getMin(minStack));       // -3
    pop(minStack);
    printf("%d\n", peek(minStack));         // 0
    printf("%d\n", getMin(minStack));       // -2

    deleteMinStack(minStack);
    return 0;
}
