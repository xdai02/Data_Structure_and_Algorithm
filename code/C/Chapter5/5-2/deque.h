#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct deque_t deque_t;

deque_t *deque_create();
void deque_destroy(deque_t *deque);
int deque_size(deque_t *deque);
bool deque_is_empty(deque_t *deque);
void deque_clear(deque_t *deque);
deque_t *deque_push_front(deque_t *deque, T elem);
deque_t *deque_push_back(deque_t *deque, T elem);
T deque_pop_front(deque_t *deque);
T deque_pop_back(deque_t *deque);
T deque_front(deque_t *deque);
T deque_back(deque_t *deque);

#endif