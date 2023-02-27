#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>

template <typename T>
class MinHeap {
    private:
    std::vector<T> data;

    public:
    MinHeap();
    int size();
    bool empty();

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



#endif