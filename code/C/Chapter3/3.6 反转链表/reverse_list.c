#include <stdio.h>
#include "linked_list.h"

Node* reverseList(Node *head) {
    if(!head || !head->next) {
        return head;
    }
    Node *next = head->next;
    head->next = NULL;
    Node *newHead = reverseList(next);
    next->next = head;
    return newHead;
}

Node* reverseListIterative(List *list) {
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->data = -1;
    newHead->next = NULL;
    Node *head = list->head->next;
    while(head) {
        Node *next = head->next;
        head->next = newHead->next;
        newHead->next = head;
        head = next;
    }
    return newHead->next;
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
    
    // recursive
    Node *newHead = reverseList(list->head->next);
    List *reversedList = initList();
    Node *reverseNodes[n];
    int i = 0;
    while(newHead) {
        reverseNodes[i] = (Node *)malloc(sizeof(Node));
        reverseNodes[i]->data = newHead->data;
        reverseNodes[i]->next = NULL;
        insert(reversedList, i, reverseNodes[i]);
        i++;
        newHead = newHead->next;
    }
    showList(reversedList);

    // iterative
    // Node *newHead = reverseListIterative(list);
    // List *reversedList = initList();
    // Node *reverseNodes[n];
    // int i = 0;
    // while(newHead) {
    //     reverseNodes[i] = (Node *)malloc(sizeof(Node));
    //     reverseNodes[i]->data = newHead->data;
    //     reverseNodes[i]->next = NULL;
    //     insert(reversedList, i, reverseNodes[i]);
    //     i++;
    //     newHead = newHead->next;
    // }
    // showList(reversedList);

    deleteList(list);
    deleteList(reversedList);
    return 0;
}