#include <stdio.h>
#include "linked_list.h"

void inverse(Node *head) {
    if(head) {
        inverse(head->next);
        printf("%d ", head->data);
    }
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

    inverse(list->head->next);
    printf("\n");

    deleteList(list);
    return 0;
}