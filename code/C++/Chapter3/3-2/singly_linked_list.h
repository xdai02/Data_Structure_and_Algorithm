#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

#include <iostream>

template <typename T>
class SinglyLinkedList {
    private:
    class Node {
        public:
        T data;
        Node *next;

        Node(T elem) {
            this->data = elem;
            this->next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    int length;

    void reverse_recursive(Node *node);

    public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    int size();
    bool empty();
    void clear();
    void add(T elem);
    void insert(int index, T elem);
    T remove(int index);
    T get(int index);
    T set(int index, T elem);
    bool contains(T elem);
    int index_of(T elem);
    void reverse_recursive();
    void reverse();

    friend std::ostream &operator<<(std::ostream &out, SinglyLinkedList<T> &list) {
        out << "[";
        Node *cur = list.head;
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
    length = 0;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
int SinglyLinkedList<T>::size() {
    return length;
}

template <typename T>
bool SinglyLinkedList<T>::empty() {
    return length == 0;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    Node *cur = head;
    while (cur != nullptr) {
        Node *del_node = cur;
        cur = cur->next;
        delete del_node;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
void SinglyLinkedList<T>::add(T elem) {
    Node *new_node = new Node(elem);
    if (tail == nullptr) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
    length++;
}

template <typename T>
void SinglyLinkedList<T>::insert(int index, T elem) {
    if (index < 0 || index > length) {
        throw "Index out of bounds";
    }

    Node *new_node = new Node(elem);
    if (index == 0) {
        new_node->next = head;
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
    } else {
        Node *prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
        if (new_node->next == nullptr) {
            tail = new_node;
        }
    }
    length++;
}

template <typename T>
T SinglyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= length) {
        throw "Index out of bounds";
    }

    Node *del_node;
    if (index == 0) {
        del_node = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node *prev = head;
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
    length--;
    return del_elem;
}

template <typename T>
T SinglyLinkedList<T>::get(int index) {
    if (index < 0 || index >= length) {
        throw "Index out of bounds";
    }

    Node *cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

template <typename T>
T SinglyLinkedList<T>::set(int index, T elem) {
    if (index < 0 || index >= length) {
        throw "Index out of bounds";
    }

    Node *cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    T old_elem = cur->data;
    cur->data = elem;
    return old_elem;
}

template <typename T>
bool SinglyLinkedList<T>::contains(T elem) {
    Node *cur = head;
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
    Node *cur = head;
    for (int i = 0; i < length; i++) {
        if (cur->data == elem) {
            return i;
        }
        cur = cur->next;
    }
    return -1;
}

template <typename T>
void SinglyLinkedList<T>::reverse_recursive(Node *node) {
    if (node->next == nullptr) {
        head = node;
        return;
    }
    reverse_recursive(node->next);
    node->next->next = node;
    node->next = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::reverse_recursive() {
    if (head == nullptr) {
        return;
    }
    reverse_recursive(*head);
    tail = head;
}

template <typename T>
void SinglyLinkedList<T>::reverse() {
    if (head == nullptr) {
        return;
    }
    Node *prev = nullptr;
    Node *cur = head;
    while (cur != nullptr) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    tail = head;
    head = prev;
}

#endif