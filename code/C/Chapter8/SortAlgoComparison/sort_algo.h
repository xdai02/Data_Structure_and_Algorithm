#ifndef _SORT_ALGO_H_
#define _SORT_ALGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

void *bubble_sort(void *args);
void *bubble_sort_opt_v1(void *args);
void *bubble_sort_opt_v2(void *args);

void *selection_sort(void *args);
void *selection_sort_opt(void *args);

void *insertion_sort(void *args);
void *insertion_sort_opt(void *args);

void *shell_sort(void *args);
void *shell_sort_opt_hibbard(void *args);
void *shell_sort_opt_sedgewick(void *args);

#endif