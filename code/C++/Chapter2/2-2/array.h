#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

template <typename T>
class Array {
    private:
    T* data;
    int size;
    int capacity;

    void resize();

    public:
    Array();
    ~Array();
    int length();
    bool empty();
    void clear();
    void append(T elem);
    void insert(int index, T elem);
    void remove(int index);
    T get(int index);
    void set(int index, T elem);
    bool contains(T elem);
    int index(T elem);
    int last_index(T elem);

    friend std::ostream& operator<<(std::ostream& out, Array<T>& arr) {
        out << "[";
        for (int i = 0; i < arr.size; i++) {
            out << arr.data[i];
            if (i != arr.size - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

template <typename T>
Array<T>::Array() {
    const int INIT_CAPACITY = 5;
    data = new T[INIT_CAPACITY];
    size = 0;
    capacity = INIT_CAPACITY;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
int Array<T>::length() {
    return size;
}

template <typename T>
bool Array<T>::empty() {
    return size == 0;
}

template <typename T>
void Array<T>::clear() {
    size = 0;
}

template <typename T>
void Array<T>::resize() {
    T* new_data = new T[capacity * 2];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity *= 2;
}

template <typename T>
void Array<T>::append(T elem) {
    if (size == capacity) {
        resize();
    }
    data[size] = elem;
    size++;
}

template <typename T>
void Array<T>::insert(int index, T elem) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }

    if (size == capacity) {
        resize(2 * capacity);
    }
    for (int i = size - 1; i >= index; i--) {
        data[i + 1] = data[i];
    }
    data[index] = elem;
    size++;
}

template <typename T>
void Array<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

template <typename T>
T Array<T>::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void Array<T>::set(int index, T elem) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = elem;
}

template <typename T>
bool Array<T>::contains(T elem) {
    for (int i = 0; i < size; i++) {
        if (data[i] == elem) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Array<T>::index(T elem) {
    for (int i = 0; i < size; i++) {
        if (data[i] == elem) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int Array<T>::last_index(T elem) {
    for (int i = size - 1; i >= 0; i--) {
        if (data[i] == elem) {
            return i;
        }
    }
    return -1;
}

#endif