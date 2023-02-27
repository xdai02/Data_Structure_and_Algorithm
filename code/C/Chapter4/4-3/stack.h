#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct stack_t stack_t;

stack_t *stack_create();
void stack_destroy(stack_t *stack);
int stack_size(stack_t *stack);
bool stack_is_empty(stack_t *stack);
void stack_clear(stack_t *stack);
stack_t *stack_push(stack_t *stack, T elem);
T stack_pop(stack_t *stack);
T stack_peek(stack_t *stack);

#endif