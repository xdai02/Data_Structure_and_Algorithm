#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct binary_search_tree_t binary_search_tree_t;

binary_search_tree_t *binary_search_tree_create();
bool binary_search_tree_is_empty(binary_search_tree_t *tree);
int binary_search_tree_size(binary_search_tree_t *tree);
int binary_search_tree_height(binary_search_tree_t *tree);
void binary_search_tree_clear(binary_search_tree_t *tree);
bool binary_search_tree_contains(binary_search_tree_t *tree, T elem);
binary_search_tree_t *binary_search_tree_add(binary_search_tree_t *tree, T elem);
binary_search_tree_t *binary_search_tree_remove(binary_search_tree_t *tree, T elem);
void binary_search_tree_pre_order(binary_search_tree_t *tree);
void binary_search_tree_in_order(binary_search_tree_t *tree);
void binary_search_tree_post_order(binary_search_tree_t *tree);
void binary_search_tree_level_order(binary_search_tree_t *tree);

#endif