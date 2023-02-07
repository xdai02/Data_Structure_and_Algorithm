#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct node_t node_t;
typedef struct singly_linked_list_t singly_linked_list_t;

singly_linked_list_t *singly_linked_list_create();
void singly_linked_list_destroy(singly_linked_list_t *list);
int singly_linked_list_size(singly_linked_list_t *list);
bool singly_linked_list_is_empty(singly_linked_list_t *list);
singly_linked_list_t *singly_linked_list_clear(singly_linked_list_t *list);
void singly_linked_list_print(singly_linked_list_t *list);
singly_linked_list_t *singly_linked_list_insert(singly_linked_list_t *list, int index, T elem);
singly_linked_list_t *singly_linked_list_remove(singly_linked_list_t *list, int index);
T singly_linked_list_get(singly_linked_list_t *list, int index);
singly_linked_list_t *singly_linked_list_set(singly_linked_list_t *list, int index, T elem);
bool singly_linked_list_contains(singly_linked_list_t *list, T elem);
int singly_linked_list_index_of(singly_linked_list_t *list, T elem);