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
    void enqueue(T elem);
    T dequeue();
    T front();
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
void Queue<T>::enqueue(T elem) {
    data.push_back(elem);
}

template <typename T>
T Queue<T>::dequeue() {
    T elem = data.front();
    data.pop_front();
    return elem;
}

template <typename T>
T Queue<T>::front() {
    return data.front();
}

#endif