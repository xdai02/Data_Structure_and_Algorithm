#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct node_t node_t;
typedef struct doubly_linked_list_t doubly_linked_list_t;

doubly_linked_list_t *doubly_linked_list_create();
void doubly_linked_list_destroy(doubly_linked_list_t *list);
int doubly_linked_list_size(doubly_linked_list_t *list);
bool doubly_linked_list_is_empty(doubly_linked_list_t *list);
doubly_linked_list_t *doubly_linked_list_clear(doubly_linked_list_t *list);
void doubly_linked_list_print(doubly_linked_list_t *list);
doubly_linked_list_t *doubly_linked_list_add(doubly_linked_list_t *list, T elem);
doubly_linked_list_t *doubly_linked_list_insert(doubly_linked_list_t *list, int index, T elem);
doubly_linked_list_t *doubly_linked_list_remove(doubly_linked_list_t *list, int index);
T doubly_linked_list_get(doubly_linked_list_t *list, int index);
doubly_linked_list_t *doubly_linked_list_set(doubly_linked_list_t *list, int index, T elem);
bool doubly_linked_list_contains(doubly_linked_list_t *list, T elem);
int doubly_linked_list_index_of(doubly_linked_list_t *list, T elem);
doubly_linked_list_t *doubly_linked_list_reverse_recursive(doubly_linked_list_t *list);
doubly_linked_list_t *doubly_linked_list_reverse(doubly_linked_list_t *list);

#endif