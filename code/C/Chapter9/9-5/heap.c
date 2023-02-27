#include "heap.h"
#include "array.h"

typedef struct min_heap_t {
    array_t *data;
} min_heap_t;

min_heap_t *min_heap_create() {
    min_heap_t *heap = (min_heap_t *)malloc(sizeof(min_heap_t));
    if (heap == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    heap->data = array_create();
    return heap;
}

void min_heap_destroy(min_heap_t *heap) {
    if (heap == NULL) {
        return;
    }
    array_destroy(heap->data);
    free(heap);
}

int min_heap_size(min_heap_t *heap) {
    if (heap == NULL) {
        return 0;
    }
    return array_size(heap->data);
}

bool min_heap_is_empty(min_heap_t *heap) {
    if (heap == NULL) {
        return true;
    }
    return array_is_empty(heap->data);
}

void min_heap_clear(min_heap_t *heap) {
    if (heap == NULL) {
        return;
    }
    array_clear(heap->data);
}

static void __min_heap_sift_up(min_heap_t *heap, int index) {
    int parent_index = (index - 1) / 2;
    while (parent_index >= 0 && array_get(heap->data, parent_index) > array_get(heap->data, index)) {
        T temp = array_get(heap->data, parent_index);
        array_set(heap->data, parent_index, array_get(heap->data, index));
        array_set(heap->data, index, temp);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

static void __min_heap_sift_down(min_heap_t *heap, int index) {
    int child_index = 2 * index + 1;
    while (child_index < array_size(heap->data)) {
        if (child_index + 1 < array_size(heap->data) && array_get(heap->data, child_index + 1) < array_get(heap->data, child_index)) {
            child_index += 1;
        }
        if (array_get(heap->data, index) <= array_get(heap->data, child_index)) {
            break;
        }
        T temp = array_get(heap->data, index);
        array_set(heap->data, index, array_get(heap->data, child_index));
        array_set(heap->data, child_index, temp);
        index = child_index;
        child_index = 2 * index + 1;
    }
}

T min_heap_pop(min_heap_t *heap) {
    if (heap == NULL) {
        exit(1);
    }

    if (array_is_empty(heap->data)) {
        exit(1);
    }

    T elem = array_get(heap->data, 0);
    array_set(heap->data, 0, array_get(heap->data, array_size(heap->data) - 1));
    array_remove(heap->data, array_size(heap->data) - 1);
    __min_heap_sift_down(heap, 0);
    return elem;
}

void min_heap_push(min_heap_t *heap, T elem) {
    if (heap == NULL) {
        return;
    }

    array_add(heap->data, elem);
    __min_heap_sift_up(heap, array_size(heap->data) - 1);
}

T min_heap_peek(min_heap_t *heap) {
    if (heap == NULL) {
        exit(1);
    }

    if (array_is_empty(heap->data)) {
        exit(1);
    }

    return array_get(heap->data, 0);
}

typedef struct max_heap_t {
    array_t *data;
} max_heap_t;

max_heap_t *max_heap_create() {
    max_heap_t *heap = (max_heap_t *)malloc(sizeof(max_heap_t));
    if (heap == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    heap->data = array_create();
    return heap;
}

void max_heap_destroy(max_heap_t *heap) {
    if (heap == NULL) {
        return;
    }
    array_destroy(heap->data);
    free(heap);
}

int max_heap_size(max_heap_t *heap) {
    if (heap == NULL) {
        return 0;
    }
    return array_size(heap->data);
}

bool max_heap_is_empty(max_heap_t *heap) {
    if (heap == NULL) {
        return true;
    }
    return array_is_empty(heap->data);
}

void max_heap_clear(max_heap_t *heap) {
    if (heap == NULL) {
        return;
    }
    array_clear(heap->data);
}

static void __max_heap_sift_up(max_heap_t *heap, int index) {
    int parent_index = (index - 1) / 2;
    while (parent_index >= 0 && array_get(heap->data, parent_index) < array_get(heap->data, index)) {
        T temp = array_get(heap->data, parent_index);
        array_set(heap->data, parent_index, array_get(heap->data, index));
        array_set(heap->data, index, temp);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

static void __max_heap_sift_down(max_heap_t *heap, int index) {
    int child_index = 2 * index + 1;
    while (child_index < array_size(heap->data)) {
        if (child_index + 1 < array_size(heap->data) && array_get(heap->data, child_index + 1) > array_get(heap->data, child_index)) {
            child_index += 1;
        }
        if (array_get(heap->data, index) >= array_get(heap->data, child_index)) {
            break;
        }
        T temp = array_get(heap->data, index);
        array_set(heap->data, index, array_get(heap->data, child_index));
        array_set(heap->data, child_index, temp);
        index = child_index;
        child_index = 2 * index + 1;
    }
}

void max_heap_push(max_heap_t *heap, T elem) {
    if (heap == NULL) {
        return;
    }
    array_add(heap->data, elem);
    __max_heap_sift_up(heap, array_size(heap->data) - 1);
}

T max_heap_pop(max_heap_t *heap) {
    if (heap == NULL) {
        exit(1);
    }

    if (array_is_empty(heap->data)) {
        exit(1);
    }

    T elem = array_get(heap->data, 0);
    array_set(heap->data, 0, array_get(heap->data, array_size(heap->data) - 1));
    array_remove(heap->data, array_size(heap->data) - 1);
    __max_heap_sift_down(heap, 0);
    return elem;
}

T max_heap_peek(max_heap_t *heap) {
    if (heap == NULL) {
        exit(1);
    }
    if (array_is_empty(heap->data)) {
        exit(1);
    }
    return array_get(heap->data, 0);
}