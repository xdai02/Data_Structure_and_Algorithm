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

        Node(T data, Node *prev = nullptr, Node *next = nullptr) {
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
    };

    Node *head;
    Node *tail;
    int size;

    void reverse_recursive(Node *node);

    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int get_size();
    bool is_empty();
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
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
int DoublyLinkedList<T>::get_size() {
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::is_empty() {
    return size == 0;
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
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::add(T elem) {
    Node *new_node = new Node(elem, tail, nullptr);
    if (tail != nullptr) {
        tail->next = new_node;
    }
    tail = new_node;
    if (head == nullptr) {
        head = new_node;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(int index, T elem) {
    if (index < 0 || index > size) {
        throw "Index out of bounds";
    }

    if (index == 0) {
        Node *new_node = new Node(elem, nullptr, head);
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
    } else if (index == size) {
        Node *new_node = new Node(elem, tail, nullptr);
        tail->next = new_node;
        tail = new_node;
    } else {
        Node *cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        Node *new_node = new Node(elem, cur->prev, cur);
        cur->prev->next = new_node;
        cur->prev = new_node;
    }
    size++;
}

template <typename T>
T DoublyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
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
    } else if (index == size - 1) {
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
    T del_data = del_node->data;
    delete del_node;
    size--;
    return del_data;
}

template <typename T>
T DoublyLinkedList<T>::get(int index) {
    if (index < 0 || index >= size) {
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
    if (index < 0 || index >= size) {
        throw "Index out of bounds";
    }

    Node *cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    T old_data = cur->data;
    cur->data = elem;
    return old_data;
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