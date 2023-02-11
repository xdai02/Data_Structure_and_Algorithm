#include "doubly_linked_list.h"

typedef struct node_t {
    T data;
    struct node_t *prev;
    struct node_t *next;
} node_t;

typedef struct doubly_linked_list_t {
    node_t *head;
    node_t *tail;
    int size;
} doubly_linked_list_t;

doubly_linked_list_t *doubly_linked_list_create() {
    doubly_linked_list_t *list = (doubly_linked_list_t *)malloc(sizeof(doubly_linked_list_t));
    if (!list) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void doubly_linked_list_destroy(doubly_linked_list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

int doubly_linked_list_size(doubly_linked_list_t *list) {
    return list->size;
}

bool doubly_linked_list_is_empty(doubly_linked_list_t *list) {
    return list->size == 0;
}

doubly_linked_list_t *doubly_linked_list_clear(doubly_linked_list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void doubly_linked_list_print(doubly_linked_list_t *list) {
    node_t *node = list->head;
    printf("[");
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
        if (node != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

doubly_linked_list_t *doubly_linked_list_add(doubly_linked_list_t *list, T elem) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (!node) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
    node->data = elem;
    node->prev = list->tail;
    node->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = node;
    }
    list->tail = node;
    if (list->head == NULL) {
        list->head = node;
    }
    list->size++;
    return list;
}

doubly_linked_list_t *doubly_linked_list_insert(doubly_linked_list_t *list, int index, T elem) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Error: index out of bounds.\n");
        exit(1);
    }

    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (!node) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
    node->data = elem;

    if (index == 0) {
        node->prev = NULL;
        node->next = list->head;
        if (list->head != NULL) {
            list->head->prev = node;
        }
        list->head = node;
        if (list->tail == NULL) {
            list->tail = node;
        }
    } else if (index == list->size) {
        node->prev = list->tail;
        node->next = NULL;
        if (list->tail != NULL) {
            list->tail->next = node;
        }
        list->tail = node;
        if (list->head == NULL) {
            list->head = node;
        }
    } else {
        node_t *prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node_t *next = prev->next;
        node->prev = prev;
        node->next = next;
        prev->next = node;
        next->prev = node;
    }

    list->size++;
    return list;
}

T doubly_linked_list_remove(doubly_linked_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: index out of bounds.\n");
        exit(1);
    }

    node_t *node;
    if (index == 0) {
        node = list->head;
        list->head = node->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
        if (list->tail == node) {
            list->tail = NULL;
        }
    } else if (index == list->size - 1) {
        node = list->tail;
        list->tail = node->prev;
        if (list->tail != NULL) {
            list->tail->next = NULL;
        }
        if (list->head == node) {
            list->head = NULL;
        }
    } else {
        node = list->head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        node_t *prev = node->prev;
        node_t *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    T elem = node->data;
    free(node);
    list->size--;
    return elem;
}

T doubly_linked_list_get(doubly_linked_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: index out of bounds.\n");
        exit(1);
    }

    if (index == list->size - 1) {
        return list->tail->data;
    }
    
    node_t *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

doubly_linked_list_t *doubly_linked_list_set(doubly_linked_list_t *list, int index, T elem) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: index out of bounds.\n");
        exit(1);
    }

    node_t *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->data = elem;
    return list;
}

bool doubly_linked_list_contains(doubly_linked_list_t *list, T elem) {
    node_t *node = list->head;
    while (node != NULL) {
        if (node->data == elem) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int doubly_linked_list_index_of(doubly_linked_list_t *list, T elem) {
    node_t *node = list->head;
    int index = 0;
    while (node != NULL) {
        if (node->data == elem) {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}

static doubly_linked_list_t *__doubly_linked_list_reverse_recursive(doubly_linked_list_t *list, node_t *node) {
    if (!node) {
        return list;
    }
    node_t *next = node->next;
    node->next = node->prev;
    node->prev = next;
    if (node->prev == NULL) {
        list->head = node;
    }
    if (node->next == NULL) {
        list->tail = node;
    }
    return __doubly_linked_list_reverse_recursive(list, next);
}

doubly_linked_list_t *doubly_linked_list_reverse_recursive(doubly_linked_list_t *list) {
    return __doubly_linked_list_reverse_recursive(list, list->head);
}

doubly_linked_list_t *doubly_linked_list_reverse(doubly_linked_list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        node_t *next = node->next;
        node->next = node->prev;
        node->prev = next;
        node = next;
    }
    node_t *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
    return list;
}