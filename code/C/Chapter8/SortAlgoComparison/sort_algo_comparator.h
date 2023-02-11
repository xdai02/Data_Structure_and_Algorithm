#ifndef _SORT_ALGO_COMPARATOR_H_
#define _SORT_ALGO_COMPARATOR_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct sort_algo_comparator sort_algo_comparator;

typedef struct argument_t {
    int *data;
    int n;
} argument_t;

sort_algo_comparator *sort_algo_comparator_create();
void sort_algo_comparator_destroy(sort_algo_comparator *comparator);
int sort_algo_comparator_read_data(sort_algo_comparator *comparator, const char *filename);
void sort_algo_comparator_sort(sort_algo_comparator *comparator, void *(*sort)(void *args), const char *algo_name, int timeout);

#endif