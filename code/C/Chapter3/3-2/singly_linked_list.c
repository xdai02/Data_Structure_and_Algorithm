#include "singly_linked_list.h"

typedef struct node_t {
    T data;
    struct node_t *next;
} node_t;

typedef struct singly_linked_list_t {
    node_t *head;
    node_t *tail;
    int size;
} singly_linked_list_t;

singly_linked_list_t *singly_linked_list_create() {
    singly_linked_list_t *list = (singly_linked_list_t *)malloc(sizeof(singly_linked_list_t));
    if (list == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void singly_linked_list_destroy(singly_linked_list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

int singly_linked_list_size(singly_linked_list_t *list) {
    return list->size;
}

bool singly_linked_list_is_empty(singly_linked_list_t *list) {
    return list->size == 0;
}

singly_linked_list_t *singly_linked_list_clear(singly_linked_list_t *list) {
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

void singly_linked_list_print(singly_linked_list_t *list) {
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

singly_linked_list_t *singly_linked_list_add(singly_linked_list_t *list, T elem) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
    node->data = elem;
    node->next = NULL;

    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return list;
}

singly_linked_list_t *singly_linked_list_insert(singly_linked_list_t *list, int index, T elem) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }

    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
    node->data = elem;

    if (index == 0) {
        node->next = list->head;
        list->head = node;
        if (list->tail == NULL) {
            list->tail = node;
        }
    } else {
        node_t *prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
        if (node->next == NULL) {
            list->tail = node;
        }
    }
    list->size++;
    return list;
}

singly_linked_list_t *singly_linked_list_remove(singly_linked_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }

    node_t *node = NULL;
    if (index == 0) {
        node = list->head;
        list->head = node->next;
        if (list->tail == node) {
            list->tail = NULL;
        }
    } else {
        node_t *prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node = prev->next;
        prev->next = node->next;
        if (node->next == NULL) {
            list->tail = prev;
        }
    }
    free(node);
    list->size--;
    return list;
}

T singly_linked_list_get(singly_linked_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }

    node_t *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

singly_linked_list_t *singly_linked_list_set(singly_linked_list_t *list, int index, T elem) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }

    node_t *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->data = elem;
    return list;
}

bool singly_linked_list_contains(singly_linked_list_t *list, T elem) {
    node_t *node = list->head;
    while (node != NULL) {
        if (node->data == elem) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int singly_linked_list_index_of(singly_linked_list_t *list, T elem) {
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

static node_t *__singly_linked_list_reverse_recursive(node_t *node) {
    if (node == NULL || node->next == NULL) {
        return node;
    }
    node_t *new_head = __singly_linked_list_reverse_recursive(node->next);
    node->next->next = node;
    node->next = NULL;
    return new_head;
}

singly_linked_list_t *singly_linked_list_reverse_recursive(singly_linked_list_t *list) {
    list->tail = list->head;
    list->head = __singly_linked_list_reverse_recursive(list->head);
    return list;
}

singly_linked_list_t *singly_linked_list_reverse(singly_linked_list_t *list) {
    node_t *prev = NULL;
    node_t *current = list->head;
    node_t *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->tail = list->head;
    list->head = prev;
    return list;
}