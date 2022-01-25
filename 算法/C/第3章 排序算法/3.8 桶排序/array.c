#include "array.h"

Array* initArray() {
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->data = (dataType *)malloc(5 * sizeof(dataType));
    arr->size = 0;
    arr->max = 5;
    return arr;
}

int getArrayLength(Array *arr) {
    return arr->size;
}

bool isFull(Array *arr) {
    return arr->size == arr->max;
}

bool isEmptyArray(Array *arr) {
	return arr->size == 0;
}

void showArray(Array *arr) {
    for(int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

/**
 * @brief  数组扩容
 * @note   2倍扩容
 * @param  arr: 数组
 * @retval 扩容后数组结构指针
 */
Array* resize(Array *arr) {
    // 2倍扩容
    arr->data = realloc(arr->data, (arr->max * 2) * sizeof(dataType));
    if(!arr->data) {
        return arr;
    }
    arr->max *= 2;
    return arr;
}

void append(Array *arr, dataType val) {
	// 数组已满，需要扩容
    if(isFull(arr)) {
        int oldSize = arr->max;
		arr = resize(arr);
        int newSize = arr->max;
        if(oldSize == newSize) {
            return;
        }
	}
    arr->data[arr->size++] = val;
}

void insert(Array *arr, int index, dataType val) {
	// 数组已满，需要扩容
    if(isFull(arr)) {
        int oldSize = arr->max;
		arr = resize(arr);
        int newSize = arr->max;
        if(oldSize == newSize) {
            return;
        }
	}

    if(index >= arr->size) {
        append(arr, val);
    }

    for(int i = arr->size - 1; i >= index; i--) {
        arr->data[i+1] = arr->data[i];
    }
    arr->data[index] = val;
    arr->size++;
}

void delete(Array *arr, int index) {
    for(int i = index + 1; i < arr->size; i++) {
        arr->data[i-1] = arr->data[i];
    }
    arr->size--;
}

dataType get(Array *arr, int index) {
	return arr->data[index];
}

void set(Array *arr, int index, dataType val) {
    arr->data[index] = val;
}

void clearArray(Array *arr) {
    arr->size = 0;
}

void deleteArray(Array *arr) {
    free(arr->data);
    free(arr);
}