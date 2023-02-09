#include "stack.h"
#include "array.h"

typedef struct stack_t {
    array_t *data;
} stack_t;

stack_t *stack_create() {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    if (stack == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    stack->data = array_create();
    return stack;
}

void stack_destroy(stack_t *stack) {
    array_destroy(stack->data);
    free(stack);
}

int stack_size(stack_t *stack) {
    return array_size(stack->data);
}

bool stack_is_empty(stack_t *stack) {
    return array_is_empty(stack->data);
}

stack_t *stack_clear(stack_t *stack) {
    array_clear(stack->data);
    return stack;
}

stack_t *stack_push(stack_t *stack, T elem) {
    array_append(stack->data, elem);
    return stack;
}

T stack_pop(stack_t *stack) {
    return array_remove(stack->data, stack_size(stack) - 1);
}

T stack_peek(stack_t *stack) {
    return array_get(stack->data, stack_size(stack) - 1);
}