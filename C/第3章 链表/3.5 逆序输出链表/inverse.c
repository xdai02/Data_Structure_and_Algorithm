#include <stdio.h>
#include "linked_list.h"
#include "stack.h"

void inverse(Node *head) {
    if(head) {
        inverse(head->next);
        printf("%d ", head->data);
    }
}

void inverseNonRecursive(List *list) {
    Stack *s = initStack(getListLength(list));

    Node *node = list->head->next;
    while(node) {
        push(s, node->data);
        node = node->next;
    }

    while(!isEmptyStack(s)) {
        printf("%d ", pop(s));
    }
    printf("\n");

    deleteStack(s);
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

    inverseNonRecursive(list);

    deleteList(list);
    return 0;
}