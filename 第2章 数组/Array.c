#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct {
    dataType *data;
    int size;       // 数组元素个数
    int max;        // 数组容量
} Array;

/**
 * @brief  初始化数组
 * @param  n: 数组容量
 * @retval 数组结构指针
 */
Array* init(int n) {
    Array *arr = (Array *)malloc(sizeof(Array));
    if(!arr) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    arr->data = (dataType *)malloc(n * sizeof(dataType));
    if(!arr->data) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    arr->size = 0;
    arr->max = n;
    return arr;
}

/**
 * @brief  计算数组元素个数
 * @param  arr: 数组
 * @retval 数组元素个数
 */
int getLength(Array *arr) {
    return arr->size;
}

/**
 * @brief  判断数组是否已满
 * @param  arr: 数组
 * @retval 满数组返回true，未满返回false
 */
bool isFull(Array *arr) {
    return arr->size == arr->max;
}

/**
 * @brief  判断数组是否为空
 * @param  arr: 数组
 * @retval 空数组返回true，非空返回false
 */
bool isEmpty(Array *arr) {
	return arr->size == 0;
}

/**
 * @brief  打印数组
 * @param  arr: 数组
 */
void show(Array *arr) {
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
    // 扩容失败，返回原数组
    if(!arr->data) {
        fprintf(stderr, "Error: array resize failed.\n");
        return arr;
    }
    arr->max *= 2;
    return arr;
}

/**
 * @brief  追加元素
 * @param  arr: 数组
 * @param  val: 插入元素
 */
void append(Array *arr, dataType val) {
	// 数组已满，需要扩容
    if(isFull(arr)) {
        int oldSize = arr->max;
		arr = resize(arr);  // 扩容
        int newSize = arr->max;
        // 如果扩容前后大小相同，说明扩容失败
        if(oldSize == newSize) {
            return;
        }
	}
    arr->data[arr->size++] = val;
}

/**
 * @brief  插入元素
 * @param  arr: 数组
 * @param  index: 插入位置
 * @param  val: 插入元素
 */
void insert(Array *arr, int index, dataType val) {
	// 数组已满，需要扩容
    if(isFull(arr)) {
        int oldSize = arr->max;
		arr = resize(arr);  // 扩容
        int newSize = arr->max;
        // 如果扩容前后大小相同，说明扩容失败
        if(oldSize == newSize) {
            return;
        }
	}

    // 超出数组范围
    if(index < 0 || index >= arr->max) {
        fprintf(stderr, "Error: index out of bound.\n");
        return;
    }

    // 数组元素个数 <= 插入位置 < 容量
    // 追加元素
    if(index >= arr->size) {
        append(arr, val);
    }

    // 将[index, size-1]的元素往后挪动一位
    for(int i = arr->size - 1; i >= index; i--) {
        arr->data[i+1] = arr->data[i];
    }
    // 插入元素
    arr->data[index] = val;
    arr->size++;
}

/**
 * @brief  删除元素
 * @param  arr: 数组
 * @param  index: 删除元素下标
 */
void delete(Array *arr, int index) {
	// 超出数组范围
    if(index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        return;
    }

    // 将[index+1, size-1]的元素都向前挪动一位
    for(int i = index + 1; i < arr->size; i++) {
        arr->data[i-1] = arr->data[i];
    }
    arr->size--;
}

/**
 * @brief  获取数组元素
 * @note   可能引发异常
 * @param  arr: 数组
 * @param  index: 获取元素下标
 * @retval 元素内容
 */
dataType get(Array *arr, int index) {
	// 超出数组范围
    if(index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        exit(1);
    }
	return arr->data[index];
}

/**
 * @brief  修改数组元素
 * @param  arr: 数组
 * @param  index: 修改元素下标
 * @param  val: 修改至
 */
void set(Array *arr, int index, dataType val) {
    // 超出数组范围
    if(index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: index out of bound.\n");
        return;
    }
    arr->data[index] = val;
}

int main() {
    Array *arr = init(5);

    append(arr, 1);     // [1]
    append(arr, 2);     // [1, 2]
    append(arr, 3);     // [1, 2, 3]
    show(arr);

    insert(arr, 0, 4);  // [4, 1, 2, 3]
    insert(arr, 1, 5);  // [4, 5, 1, 2, 3]
    show(arr);

    delete(arr, 3);     // [4, 5, 1, 3]
    delete(arr, 2);     // [4, 5, 3]
    show(arr);

    set(arr, 0, 6);     // [6, 5, 3]
    set(arr, 2, 7);     // [6, 5, 7]
    show(arr);

    printf("%d\n", get(arr, 0));    // 6
    free(arr);
    
    return 0;
}