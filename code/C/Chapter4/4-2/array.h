#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct array_t array_t;

array_t *array_create();
int array_size(array_t *arr);
bool array_is_empty(array_t *arr);
array_t *array_clear(array_t *arr);
void array_print(array_t *arr);
array_t *array_append(array_t *arr, T elem);
array_t *array_insert(array_t *arr, int index, T elem);
T array_remove(array_t *arr, int index);
T array_get(array_t *arr, int index);
array_t *array_set(array_t *arr, int index, T elem);
bool array_contains(array_t *arr, T elem);
int array_index(array_t *arr, T elem);
int array_last_index(array_t *arr, T elem);
array_t *array_destroy(array_t *arr);

#endif