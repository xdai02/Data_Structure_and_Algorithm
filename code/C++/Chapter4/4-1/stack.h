#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <vector>

template <typename T>
class Stack {
    private:
    std::vector<T> data;

    public:
    bool empty();
    int size();
    void push(T elem);
    T pop();
    T top();
};

template <typename T>
bool Stack<T>::empty() {
    return data.empty();
}

template <typename T>
int Stack<T>::size() {
    return data.size();
}

template <typename T>
void Stack<T>::push(T elem) {
    data.push_back(elem);
}

template <typename T>
T Stack<T>::pop() {
    T elem = data.back();
    data.pop_back();
    return elem;
}

template <typename T>
T Stack<T>::top() {
    return data.back();
}

#endif