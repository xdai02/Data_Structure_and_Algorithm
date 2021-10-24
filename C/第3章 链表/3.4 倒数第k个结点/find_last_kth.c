#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* findLastKth(List *list, int k) {
    Node *p1 = list->head;
    Node *p2 = list->head;

    int i = 0;
    while(p2->next && i < k) {
        p2 = p2->next;
        i++;
    }
    while(p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

int main() {
    List *list = initList();

    int n = 6;
    Node *nodes[n];
    for(int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->data = i;
        nodes[i]->next = NULL;
        insert(list, i, nodes[i]);
    }

    // [0, 1, 2, 3, 4, 5]
    printf("%d\n", findLastKth(list, 3)->data);

    deleteList(list);
    return 0;
}