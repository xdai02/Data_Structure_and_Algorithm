#include "deque.h"
#include "doubly_linked_list.h"

typedef struct deque_t {
    doubly_linked_list_t *data;
} deque_t;

deque_t *deque_create() {
    deque_t *deque = (deque_t *)malloc(sizeof(deque_t));
    if (deque == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    deque->data = doubly_linked_list_create();
    return deque;
}

void deque_destroy(deque_t *deque) {
    if (deque == NULL) {
        return;
    }
    doubly_linked_list_destroy(deque->data);
    free(deque);
}

int deque_size(deque_t *deque) {
    if (deque == NULL) {
        return 0;
    }
    return doubly_linked_list_size(deque->data);
}

bool deque_is_empty(deque_t *deque) {
    if (deque == NULL) {
        return true;
    }
    return doubly_linked_list_is_empty(deque->data);
}

void deque_clear(deque_t *deque) {
    if (deque == NULL) {
        return;
    }
    doubly_linked_list_clear(deque->data);
}

deque_t *deque_push_front(deque_t *deque, T elem) {
    if (deque == NULL) {
        return NULL;
    }
    doubly_linked_list_insert(deque->data, 0, elem);
    return deque;
}

deque_t *deque_push_back(deque_t *deque, T elem) {
    if (deque == NULL) {
        return NULL;
    }
    doubly_linked_list_add(deque->data, elem);
    return deque;
}

T deque_pop_front(deque_t *deque) {
    if (deque == NULL) {
        exit(1);
    }
    return doubly_linked_list_remove(deque->data, 0);
}

T deque_pop_back(deque_t *deque) {
    if (deque == NULL) {
        exit(1);
    }
    return doubly_linked_list_remove(deque->data, doubly_linked_list_size(deque->data) - 1);
}

T deque_front(deque_t *deque) {
    if (deque == NULL) {
        exit(1);
    }
    return doubly_linked_list_get(deque->data, 0);
}

T deque_back(deque_t *deque) {
    if (deque == NULL) {
        exit(1);
    }
    return doubly_linked_list_get(deque->data, doubly_linked_list_size(deque->data) - 1);
}