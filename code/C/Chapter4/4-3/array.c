#include "array.h"

typedef struct array_t {
    T *data;
    int size;
    int capacity;
} array_t;

array_t *array_create() {
    array_t *arr = (array_t *)malloc(sizeof(array_t));
    if (!arr) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }

    const int INIT_CAPACITY = 5;
    arr->data = (T *)malloc(sizeof(T) * INIT_CAPACITY);
    if (!arr->data) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    arr->size = 0;
    arr->capacity = INIT_CAPACITY;
    return arr;
}

void array_destroy(array_t *arr) {
    if (arr == NULL) {
        return;
    }
    free(arr->data);
    free(arr);
}

int array_size(array_t *arr) {
    if (arr == NULL) {
        return 0;
    }
    return arr->size;
}

bool array_is_empty(array_t *arr) {
    if (arr == NULL) {
        return true;
    }
    return arr->size == 0;
}

array_t *array_clear(array_t *arr) {
    if (arr == NULL) {
        return NULL;
    }
    arr->size = 0;
    return arr;
}

void array_print(array_t *arr) {
    if (arr == NULL) {
        return;
    }

    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i != arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

static array_t *resize(array_t *arr) {
    if (arr == NULL) {
        return NULL;
    }

    arr->capacity *= 2;
    arr->data = (T *)realloc(arr->data, sizeof(T) * arr->capacity);
    if (arr->data == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    return arr;
}

array_t *array_append(array_t *arr, T elem) {
    if (arr == NULL) {
        return NULL;
    }

    if (arr->size == arr->capacity) {
        arr = resize(arr);
    }
    arr->data[arr->size++] = elem;
    return arr;
}

array_t *array_insert(array_t *arr, int index, T elem) {
    if (arr == NULL) {
        return NULL;
    }

    if (index < 0 || index > arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        return arr;
    }

    if (arr->size == arr->capacity) {
        arr = resize(arr);
    }

    for (int i = arr->size - 1; i >= index; i--) {
        arr->data[i + 1] = arr->data[i];
    }
    arr->data[index] = elem;
    arr->size++;
    return arr;
}

T array_remove(array_t *arr, int index) {
    if (arr == NULL) {
        exit(1);
    }

    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }

    T elem = arr->data[index];
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return elem;
}

T array_get(array_t *arr, int index) {
    if (arr == NULL) {
        exit(1);
    }

    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }
    return arr->data[index];
}

array_t *array_set(array_t *arr, int index, T elem) {
    if (arr == NULL) {
        return NULL;
    }

    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        return arr;
    }
    arr->data[index] = elem;
    return arr;
}

bool array_contains(array_t *arr, T elem) {
    if (arr == NULL) {
        return false;
    }

    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == elem) {
            return true;
        }
    }
    return false;
}

int array_index(array_t *arr, T elem) {
    if (arr == NULL) {
        return -1;
    }

    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == elem) {
            return i;
        }
    }
    return -1;
}

int array_last_index(array_t *arr, T elem) {
    if (arr == NULL) {
        return -1;
    }

    for (int i = arr->size - 1; i >= 0; i--) {
        if (arr->data[i] == elem) {
            return i;
        }
    }
    return -1;
}