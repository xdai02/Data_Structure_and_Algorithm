#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <list>

template <typename T>
class Queue {
    private:
    std::list<T> data;

    public:
    bool empty();
    int size();
    void enqueue(T item);
    T dequeue();
};

template <typename T>
bool Queue<T>::empty() {
    return data.empty();
}

template <typename T>
int Queue<T>::size() {
    return data.size();
}

template <typename T>
void Queue<T>::enqueue(T item) {
    data.push_back(item);
}

template <typename T>
T Queue<T>::dequeue() {
    T item = data.front();
    data.pop_front();
    return item;
}

#endif