#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct {
    dataType *data;
    int size;
    int max;
} Array;

Array* initArray();

int getArrayLength(Array *arr);

bool isFullArray(Array *arr);

bool isEmptyArray(Array *arr);

void showArray(Array *arr);

Array* resize(Array *arr);

void append(Array *arr, dataType val);

void insert(Array *arr, int index, dataType val);

void delete(Array *arr, int index);

dataType get(Array *arr, int index);

void set(Array *arr, int index, dataType val);

void clearArray(Array *arr);

void deleteArray(Array *arr);

#endif  // _ARRAY_H_