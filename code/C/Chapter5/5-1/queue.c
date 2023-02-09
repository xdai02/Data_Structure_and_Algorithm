#include "queue.h"
#include "singly_linked_list.h"

typedef struct queue_t {
    singly_linked_list_t *data;
} queue_t;

queue_t *queue_create() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    queue->data = singly_linked_list_create();
    return queue;
}

void queue_destroy(queue_t *queue) {
    singly_linked_list_destroy(queue->data);
    free(queue);
}

int queue_size(queue_t *queue) {
    return singly_linked_list_size(queue->data);
}

bool queue_is_empty(queue_t *queue) {
    return singly_linked_list_is_empty(queue->data);
}

queue_t *queue_enqueue(queue_t *queue, T elem) {
    singly_linked_list_add(queue->data, elem);
    return queue;
}

T queue_dequeue(queue_t *queue) {
    return singly_linked_list_remove(queue->data, 0);
}