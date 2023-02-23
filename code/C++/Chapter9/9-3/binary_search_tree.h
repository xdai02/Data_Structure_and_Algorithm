#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream>
#include <queue>

template <typename T>
class BinarySearchTree {
    private:
    class Node {
        public:
        T data;
        Node *left;
        Node *right;

        Node(T elem) {
            this->data = elem;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node *root;
    int length;

    int height(Node *node);
    void clear(Node *node);
    Node *add(Node *node, T elem);
    Node *remove(Node *node, T elem);
    Node *min(Node *node);
    Node *max(Node *node);
    void pre_order(Node *node, std::string &str);
    void in_order(Node *node, std::string &str);
    void post_order(Node *node, std::string &str);
    void level_order(Node *node, std::string &str);

    public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool empty();
    int size();
    int height();
    void clear();
    bool contains(T elem);
    void add(T elem);
    void remove(T elem);
    std::string pre_order();
    std::string in_order();
    std::string post_order();
    std::string level_order();

    friend std::ostream &operator<<(std::ostream &out, BinarySearchTree<T> &bst) {
        out << bst.in_order();
        return out;
    }
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
    this->length = 0;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear();
}

template <typename T>
bool BinarySearchTree<T>::empty() {
    return length == 0;
}

template <typename T>
int BinarySearchTree<T>::size() {
    return length;
}

template <typename T>
int BinarySearchTree<T>::height(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return std::max(height(node->left), height(node->right)) + 1;
}

template <typename T>
int BinarySearchTree<T>::height() {
    return height(root);
}

template <typename T>
void BinarySearchTree<T>::clear(Node *node) {
    if (node == nullptr) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}

template <typename T>
void BinarySearchTree<T>::clear() {
    clear(root);
    root = nullptr;
    length = 0;
}

template <typename T>
bool BinarySearchTree<T>::contains(T elem) {
    Node *node = root;
    while (node != nullptr) {
        if (elem < node->data) {
            node = node->left;
        } else if (elem > node->data) {
            node = node->right;
        } else {
            return true;
        }
    }
    return false;
}

template <typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::add(Node *node, T elem) {
    if (node == nullptr) {
        length++;
        return new Node(elem);
    }
    if (elem < node->data) {
        node->left = add(node->left, elem);
    } else if (elem > node->data) {
        node->right = add(node->right, elem);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::add(T elem) {
    root = add(root, elem);
}

template <typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::remove(Node *node, T elem) {
    if (node == nullptr) {
        return nullptr;
    }

    if (elem < node->data) {
        node->left = remove(node->left, elem);
    } else if (elem > node->data) {
        node->right = remove(node->right, elem);
    } else {
        if (node->left == nullptr) {
            length--;
            return node->right;
        } else if (node->right == nullptr) {
            length--;
            return node->left;
        } else {
            T successor = min(node->right)->data;
            node->data = successor;
            node->right = remove(node->right, successor);
        }
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::remove(T elem) {
    root = remove(root, elem);
}

template <typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::min(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::max(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template <typename T>
std::string BinarySearchTree<T>::pre_order() {
    if (length == 0) {
        return "[]";
    }

    std::string str = "[";
    pre_order(root, str);
    str += "\b\b]";
    return str;
}

template <typename T>
void BinarySearchTree<T>::pre_order(Node *node, std::string &str) {
    if (node == nullptr) {
        return;
    }
    str += std::to_string(node->data) + ", ";
    pre_order(node->left, str);
    pre_order(node->right, str);
}

template <typename T>
std::string BinarySearchTree<T>::in_order() {
    if (length == 0) {
        return "[]";
    }

    std::string str = "[";
    in_order(root, str);
    str += "\b\b]";
    return str;
}

template <typename T>
void BinarySearchTree<T>::in_order(Node *node, std::string &str) {
    if (node == nullptr) {
        return;
    }
    in_order(node->left, str);
    str += std::to_string(node->data) + ", ";
    in_order(node->right, str);
}

template <typename T>
std::string BinarySearchTree<T>::post_order() {
    if (length == 0) {
        return "[]";
    }

    std::string str = "[";
    post_order(root, str);
    str += "\b\b]";
    return str;
}

template <typename T>
void BinarySearchTree<T>::post_order(Node *node, std::string &str) {
    if (node == nullptr) {
        return;
    }
    post_order(node->left, str);
    post_order(node->right, str);
    str += std::to_string(node->data) + ", ";
}

template <typename T>
std::string BinarySearchTree<T>::level_order() {
    if (length == 0) {
        return "[]";
    }

    std::string str = "[";
    std::queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        str += std::to_string(node->data) + ", ";
        if (node->left != nullptr) {
            queue.push(node->left);
        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
    str += "\b\b]";
    return str;
}

#endif