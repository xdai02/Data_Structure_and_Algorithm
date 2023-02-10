#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <iostream>

template <typename T>
class DoublyLinkedList {
    private:
    class Node {
        public:
        T data;
        Node *prev;
        Node *next;

        Node(T data) {
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    int length;

    void reverse_recursive(Node *node);

    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
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

    friend std::ostream &operator<<(std::ostream &out, DoublyLinkedList<T> &list) {
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
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
int DoublyLinkedList<T>::size() {
    return length;
}

template <typename T>
bool DoublyLinkedList<T>::empty() {
    return length == 0;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
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
void DoublyLinkedList<T>::add(T elem) {
    Node *new_node = new Node(elem);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(int index, T elem) {
    if (index < 0 || index > length) {
        throw "Index out of bounds";
    }

    Node *new_node = new Node(elem);
    if (index == 0) {
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    } else if (index == length) {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    } else {
        Node *cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        new_node->next = cur;
        new_node->prev = cur->prev;
        cur->prev->next = new_node;
        cur->prev = new_node;
    }
    length++;
}

template <typename T>
T DoublyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= length) {
        throw "Index out of bounds";
    }

    Node *del_node = nullptr;
    if (index == 0) {
        del_node = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        if (tail == del_node) {
            tail = nullptr;
        }
    } else if (index == length - 1) {
        del_node = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        if (head == del_node) {
            head = nullptr;
        }
    } else {
        Node *cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        del_node = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    T elem = del_node->data;
    delete del_node;
    length--;
    return elem;
}

template <typename T>
T DoublyLinkedList<T>::get(int index) {
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
T DoublyLinkedList<T>::set(int index, T elem) {
    if (index < 0 || index >= length) {
        throw "Index out of bounds";
    }

    Node *cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    T elem = cur->data;
    cur->data = elem;
    return elem;
}

template <typename T>
bool DoublyLinkedList<T>::contains(T elem) {
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
int DoublyLinkedList<T>::index_of(T elem) {
    Node *cur = head;
    int index = 0;
    while (cur != nullptr) {
        if (cur->data == elem) {
            return index;
        }
        cur = cur->next;
        index++;
    }
    return -1;
}

template <typename T>
void DoublyLinkedList<T>::reverse_recursive(Node *node) {
    if (node == nullptr) {
        return;
    }
    if (node->next == nullptr) {
        head = node;
        return;
    }
    reverse_recursive(node->next);
    node->next->next = node;
    node->next = nullptr;
    tail = node;
}

template <typename T>
void DoublyLinkedList<T>::reverse_recursive() {
    reverse_recursive(head);
}

template <typename T>
void DoublyLinkedList<T>::reverse() {
    Node *cur = head;
    while (cur != nullptr) {
        Node *temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        if (temp == nullptr) {
            head = cur;
        }
        cur = temp;
    }
    tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
}

#endif