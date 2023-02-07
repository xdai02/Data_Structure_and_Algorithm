#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

#include <iostream>

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node(T data, Node<T> *next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class SinglyLinkedList {
    private:
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    int get_size();
    bool is_empty();
    void clear();
    void insert(int index, T elem);
    T remove(int index);
    T get(int index);
    T set(int index, T elem);
    bool contains(T elem);
    int index_of(T elem);

    friend std::ostream &operator<<(std::ostream &out, SinglyLinkedList<T> &list) {
        out << "[";
        Node<T> *cur = list.head;
        while (cur != nullptr) {
            out << cur->data;
            if (cur->next != nullptr) {
                out << ", ";
            }
            cur = cur->next;
        }
        out << "]";
        return out;
    }
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
int SinglyLinkedList<T>::get_size() {
    return size;
}

template <typename T>
bool SinglyLinkedList<T>::is_empty() {
    return size == 0;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    Node<T> *cur = head;
    while (cur != nullptr) {
        Node<T> *del_node = cur;
        cur = cur->next;
        delete del_node;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void SinglyLinkedList<T>::insert(int index, T elem) {
    if (index < 0 || index > size) {
        throw "Index out of bounds";
    }

    if (index == 0) {
        head = new Node<T>(elem, head);
        if (tail == nullptr) {
            tail = head;
        }
    } else {
        Node<T> *prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        prev->next = new Node<T>(elem, prev->next);
        if (prev == tail) {
            tail = prev->next;
        }
    }
    size++;
}

template <typename T>
T SinglyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw "Index out of bounds";
    }

    Node<T> *del_node;
    if (index == 0) {
        del_node = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node<T> *prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        del_node = prev->next;
        prev->next = del_node->next;
        if (prev->next == nullptr) {
            tail = prev;
        }
    }
    T del_elem = del_node->data;
    delete del_node;
    size--;
    return del_elem;
}

template <typename T>
T SinglyLinkedList<T>::get(int index) {
    if (index < 0 || index >= size) {
        throw "Index out of bounds";
    }

    Node<T> *cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

template <typename T>
T SinglyLinkedList<T>::set(int index, T elem) {
    if (index < 0 || index >= size) {
        throw "Index out of bounds";
    }

    Node<T> *cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    T old_elem = cur->data;
    cur->data = elem;
    return old_elem;
}

template <typename T>
bool SinglyLinkedList<T>::contains(T elem) {
    Node<T> *cur = head;
    while (cur != nullptr) {
        if (cur->data == elem) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

template <typename T>
int SinglyLinkedList<T>::index_of(T elem) {
    Node<T> *cur = head;
    for (int i = 0; i < size; i++) {
        if (cur->data == elem) {
            return i;
        }
        cur = cur->next;
    }
    return -1;
}

#endif