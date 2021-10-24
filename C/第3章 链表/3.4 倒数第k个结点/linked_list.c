#include "linked_list.h"

List* initList() {
    List *list = (List *)malloc(sizeof(List));
    if(!list) {
        return NULL;
    }
    list->head = (Node *)malloc(sizeof(Node));
    if(!list->head) {
		free(list);
        return NULL;
    }
    list->head->next = NULL;
    return list;
}

int getListLength(List *list) {
    if(!list || !list->head) {
        return 0;
    }
    int cnt = 0;
    Node *cur = list->head;
    while(cur->next) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}

void showList(List *list) {
    if(!list || !list->head) {
        return;
    } 
    Node *cur = list->head;
    while(cur->next) {
        cur = cur->next;
        printf("%d ", cur->data);
    }
    printf("\n");
}

void insert(List *list, int pos, Node *node) {
    if(!list || !list->head || pos <  0 || pos > getListLength(list)) {
        return;
    }

    Node *cur = list->head;
    if(!cur->next) {
        cur->next = node;
        return;
    }

    for(int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
}

void delete(List *list, int pos) {
    if(!list || !list->head || pos <  0 || pos > getListLength(list)) {
        return;
    }

    Node *cur = list->head;
    for(int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    
    Node *del = cur->next;
    cur->next = del->next;
    free(del);
    del = NULL;
}

void deleteList(List *list) {
    if(list) {
        if(list->head) {
            while(getListLength(list) > 0) {
                delete(list, 0);
            }
            free(list->head);
            list->head = NULL;
        }
        free(list);
        list = NULL;
    }
}