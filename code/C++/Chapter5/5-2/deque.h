#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <iostream>
#include <list>

template <typename T>
class Deque {
    private:
    std::list<T> data;

    public:
    bool empty();
    int size();
    void push_front(T elem);
    void push_back(T elem);
    T pop_front();
    T pop_back();
    T front();
    T back();
};

template <typename T>
bool Deque<T>::empty() {
    return data.empty();
}

template <typename T>
int Deque<T>::size() {
    return data.size();
}

template <typename T>
void Deque<T>::push_front(T elem) {
    data.push_front(elem);
}

template <typename T>
void Deque<T>::push_back(T elem) {
    data.push_back(elem);
}

template <typename T>
T Deque<T>::pop_front() {
    T elem = data.front();
    data.pop_front();
    return elem;
}

template <typename T>
T Deque<T>::pop_back() {
    T elem = data.back();
    data.pop_back();
    return elem;
}

template <typename T>
T Deque<T>::front() {
    return data.front();
}

template <typename T>
T Deque<T>::back() {
    return data.back();
}

#endif