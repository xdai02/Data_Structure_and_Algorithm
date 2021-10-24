#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct Node {
    dataType data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

List* initList();

int getListLength(List *list);

void showList(List *list);

void insert(List *list, int pos, Node *node);

void delete(List *list, int pos);

void deleteList(List *list);

#endif