#ifndef _SORT_ALGO_H_
#define _SORT_ALGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

void *bubble_sort_v1_0(void *args);
void *bubble_sort_v2_0(void *args);
void *bubble_sort_v2_1(void *args);

void *selection_sort_v1_0(void *args);
void *selection_sort_v2_0(void *args);

void *insertion_sort_v1_0(void *args);
void *insertion_sort_v2_0(void *args);

void *shell_sort_v1_0(void *args);
void *shell_sort_hibbard(void *args);
void *shell_sort_sedgewick(void *args);

void *merge_sort_v1_0(void *args);
void *merge_sort_v2_0(void *args);
void *merge_sort_v3_0(void *args);

void *quick_sort_v1_0(void *args);
void *quick_sort_v2_0(void *args);
void *quick_sort_v2_1(void *args);
void *quick_sort_v2_2(void *args);
void *quick_sort_v3_0(void *args);

void *heap_sort_v1_0(void *args);

#endif