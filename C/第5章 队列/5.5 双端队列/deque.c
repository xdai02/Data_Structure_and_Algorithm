#include "deque.h"

Deque* initDeque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

bool isEmptyDeque(Deque *deque) {
    return deque->front == NULL;
}

void addFront(Deque *deque, dataType val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->prev = NULL;
    node->next = NULL;

    if(isEmptyDeque(deque)) {
        deque->front = node;
        deque->rear = node;
    } else {
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }
}

void addRear(Deque *deque, dataType val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->prev = NULL;
    node->next = NULL;

    if(isEmptyDeque(deque)) {
        deque->front = node;
        deque->rear = node;
    } else {
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }
}

dataType removeFront(Deque *deque) {
    Node *front = deque->front;
    int data = front->data;
    deque->front = front->next;
    if(deque->front) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(front);
    return data;
}

dataType removeRear(Deque *deque) {
    Node *rear = deque->rear;
    int data = rear->data;
    deque->rear = rear->prev;
    if(deque->rear) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(rear);
    return data;
}

dataType getFront(Deque *deque) {
    return deque->front->data;
}

dataType getRear(Deque *deque) {
    return deque->rear->data;
}

void deleteDeque(Deque *deque) {
    while(!isEmptyDeque(deque)) {
        removeFront(deque);
    }
    free(deque);
}

int main() {
    Deque *deque = initDeque();
    addFront(deque, 11);        // 11
    addFront(deque, 22);        // 22 11
    removeRear(deque);          // 22
    addRear(deque, 33);         // 22 33
    addRear(deque, 44);         // 22 33 44
    removeFront(deque);         // 33 44
    printf("%d\n", getFront(deque));
    printf("%d\n", getRear(deque));
    deleteDeque(deque);
    return 0;
}