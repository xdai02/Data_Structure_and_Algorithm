#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct min_heap_t min_heap_t;

min_heap_t *min_heap_create();
void min_heap_destroy(min_heap_t *heap);
int min_heap_size(min_heap_t *heap);
bool min_heap_is_empty(min_heap_t *heap);
void min_heap_clear(min_heap_t *heap);
void min_heap_push(min_heap_t *heap, T elem);
T min_heap_pop(min_heap_t *heap);
T min_heap_peek(min_heap_t *heap);

typedef struct max_heap_t max_heap_t;

max_heap_t *max_heap_create();
void max_heap_destroy(max_heap_t *heap);
int max_heap_size(max_heap_t *heap);
bool max_heap_is_empty(max_heap_t *heap);
void max_heap_clear(max_heap_t *heap);
void max_heap_push(max_heap_t *heap, T elem);
T max_heap_pop(max_heap_t *heap);
T max_heap_peek(max_heap_t *heap);

#endif