#include <stdio.h>
#include "linked_list.h"

Node* cycleNode(List *list) {
    Node *p1 = list->head->next;
    Node *p2 = list->head->next;

    while(p1 && p2) {
        if(!p2->next || !p2->next->next) {
            return NULL;
        }
        p1 = p1->next;
        p2 = p2->next->next;
        if(p1 == p2) {
            return p1;
        }
    }
    return NULL;
}

int cycleLength(List *list) {
    Node *node = cycleNode(list);
    if(!node) {
        return 0;
    }
    int len = 1;
    Node *cur = node->next;
    while(cur != node) {
        cur = cur->next;
        len++;
    }
    return len;
}

Node* cycleEntrance(List *list) {
    int n = cycleLength(list);
    if(n == 0) {
        return NULL;
    }

    Node *p1 = list->head->next;
    Node *p2 = list->head->next;
    for(int i = 0; i < n; i++) {
        p2 = p2->next;
    }

    while(p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

int main() {
    int n = 6;
    List *list = initList();
    Node *node = list->head;

    Node *nodes[n];
    for(int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->data = i;
        nodes[i]->next = NULL;
        insert(list, i, nodes[i]);
        node = node->next;
    }
    node->next = nodes[2];
    
    /*
        0 → 1 → 2 → 3 → 4 → 5
                ↑           ↓
                ←  ←  ←  ←  ←
    */
    printf("contains cycle: %s\n", cycleNode(list) ? "true" : "false");
    printf("cycle length: %d\n", cycleLength(list));
    printf("cycle entrance: %d\n", cycleEntrance(list)->data);

    for(int i = 0; i < n; i++) {
        free(nodes[i]);
        nodes[i] = NULL;
    }
    deleteList(list);
    return 0;
}