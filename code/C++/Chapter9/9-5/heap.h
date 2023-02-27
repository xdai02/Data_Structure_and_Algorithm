#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>

template <typename T>
class MinHeap {
    private:
    std::vector<T> data;

    void sift_up(int index);
    void sift_down(int index);

    public:
    MinHeap();
    int size();
    bool empty();
    void clear();
    void push(T elem);
    T pop();
    T top();
};

template <typename T>
MinHeap<T>::MinHeap() {
    data = std::vector<T>();
}

template <typename T>
int MinHeap<T>::size() {
    return data.size();
}

template <typename T>
bool MinHeap<T>::empty() {
    return data.empty();
}

template <typename T>
void MinHeap<T>::clear() {
    data.clear();
}

template <typename T>
void MinHeap<T>::sift_up(int index) {
    int parent_index = (index - 1) / 2;
    while (parent_index >= 0 && data[parent_index] > data[index]) {
        std::swap(data[index], data[parent_index]);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

template <typename T>
void MinHeap<T>::sift_down(int index) {
    int size = data.size();

    int child_index = 2 * index + 1;
    while (child_index < size) {
        if (child_index + 1 < size && data[child_index + 1] < data[child_index]) {
            child_index += 1;
        }
        if (data[index] <= data[child_index]) {
            break;
        }
        std::swap(data[index], data[child_index]);
        index = child_index;
        child_index = 2 * index + 1;
    }
}

template <typename T>
void MinHeap<T>::push(T elem) {
    data.push_back(elem);
    sift_up(data.size() - 1);
}

template <typename T>
T MinHeap<T>::pop() {
    T elem = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();
    sift_down(0);
    return elem;
}

template <typename T>
T MinHeap<T>::top() {
    return data[0];
}

template <typename T>
class MaxHeap {
    private:
    std::vector<T> data;

    void sift_up(int index);
    void sift_down(int index);

    public:
    MaxHeap();
    int size();
    bool empty();
    void clear();
    void push(T elem);
    T pop();
    T top();
};

template <typename T>
MaxHeap<T>::MaxHeap() {
    data = std::vector<T>();
}

template <typename T>
int MaxHeap<T>::size() {
    return data.size();
}

template <typename T>
bool MaxHeap<T>::empty() {
    return data.empty();
}

template <typename T>
void MaxHeap<T>::clear() {
    data.clear();
}

template <typename T>
void MaxHeap<T>::sift_up(int index) {
    int parent_index = (index - 1) / 2;
    while (parent_index >= 0 && data[parent_index] < data[index]) {
        std::swap(data[index], data[parent_index]);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

template <typename T>
void MaxHeap<T>::sift_down(int index) {
    int size = data.size();

    int child_index = 2 * index + 1;
    while (child_index < size) {
        if (child_index + 1 < size && data[child_index + 1] > data[child_index]) {
            child_index += 1;
        }
        if (data[index] >= data[child_index]) {
            break;
        }
        std::swap(data[index], data[child_index]);
        index = child_index;
        child_index = 2 * index + 1;
    }
}

template <typename T>
void MaxHeap<T>::push(T elem) {
    data.push_back(elem);
    sift_up(data.size() - 1);
}

template <typename T>
T MaxHeap<T>::pop() {
    T elem = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();
    sift_down(0);
    return elem;
}

template <typename T>
T MaxHeap<T>::top() {
    return data[0];
}

#endif