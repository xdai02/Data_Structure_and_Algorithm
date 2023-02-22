#include "binary_search_tree.h"
#include "queue.h"

typedef struct node_t {
    T data;
    struct node_t *left;
    struct node_t *right;
} node_t;

typedef struct binary_search_tree_t {
    node_t *root;
    size_t size;
} binary_search_tree_t;

static node_t *binary_search_tree_node_create(T elem) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    node->data = elem;
    node->left = NULL;
    node->right = NULL;
    return node;
}

binary_search_tree_t *binary_search_tree_create() {
    binary_search_tree_t *tree = malloc(sizeof(binary_search_tree_t));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

bool binary_search_tree_is_empty(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return true;
    }
    return tree->size == 0;
}

int binary_search_tree_size(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    return tree->size;
}

static int __binary_search_tree_height(node_t *node) {
    if (node == NULL) {
        return 0;
    }

    return __max(__binary_search_tree_height(node->left), __binary_search_tree_height(node->right)) + 1;
}

int binary_search_tree_height(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    return __binary_search_tree_height(tree->root);
}

bool binary_search_tree_contains(binary_search_tree_t *tree, T elem) {
    if (tree == NULL) {
        return false;
    }

    node_t *node = tree->root;
    while (node != NULL) {
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

static node_t *__binary_search_tree_add(node_t *node, T elem) {
    if (node == NULL) {
        return binary_search_tree_node_create(elem);
    }

    if (elem < node->data) {
        node->left = __binary_search_tree_add(node->left, elem);
    } else if (elem > node->data) {
        node->right = __binary_search_tree_add(node->right, elem);
    }
    return node;
}

binary_search_tree_t *binary_search_tree_add(binary_search_tree_t *tree, T elem) {
    if (tree == NULL) {
        return NULL;
    }

    tree->root = __binary_search_tree_add(tree->root, elem);
    tree->size++;
    return tree;
}

static T binary_search_tree_min(node_t *node) {
    if (node == NULL) {
        exit(1);
    }

    while (node->left != NULL) {
        node = node->left;
    }
    return node->data;
}

static T binary_search_tree_max(node_t *node) {
    if (node == NULL) {
        exit(1);
    }

    while (node->right != NULL) {
        node = node->right;
    }
    return node->data;
}

static node_t *__binary_search_tree_remove(node_t *node, T elem) {
    if (node == NULL) {
        return NULL;
    }

    if (elem < node->data) {
        node->left = __binary_search_tree_remove(node->left, elem);
        return node;
    } else if (elem > node->data) {
        node->right = __binary_search_tree_remove(node->right, elem);
        return node;
    } else {
        if (node->left == NULL) {
            node_t *right_node = node->right;
            free(node);
            return right_node;
        }

        if (node->right == NULL) {
            node_t *left_node = node->left;
            free(node);
            return left_node;
        }

        T successor = binary_search_tree_min(node->right);
        node->data = successor;
        node->right = __binary_search_tree_remove(node->right, successor);
        return node;
    }
}

binary_search_tree_t *binary_search_tree_remove(binary_search_tree_t *tree, T elem) {
    if (tree == NULL) {
        return NULL;
    }

    tree->root = __binary_search_tree_remove(tree->root, elem);
    tree->size--;
    return tree;
}

static void __binary_search_tree_pre_order(node_t *node) {
    if (node == NULL) {
        return;
    }
    printf("%d, ", node->data);
    __binary_search_tree_pre_order(node->left);
    __binary_search_tree_pre_order(node->right);
}

void binary_search_tree_pre_order(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return;
    }

    if (tree->size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    __binary_search_tree_pre_order(tree->root);
    printf("\b\b]\n");
}

static void __binary_search_tree_in_order(node_t *node) {
    if (node == NULL) {
        return;
    }
    __binary_search_tree_in_order(node->left);
    printf("%d, ", node->data);
    __binary_search_tree_in_order(node->right);
}

void binary_search_tree_in_order(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return;
    }

    if (tree->size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    __binary_search_tree_in_order(tree->root);
    printf("\b\b]\n");
}

static void __binary_search_tree_post_order(node_t *node) {
    if (node == NULL) {
        return;
    }
    __binary_search_tree_post_order(node->left);
    __binary_search_tree_post_order(node->right);
    printf("%d, ", node->data);
}

void binary_search_tree_post_order(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return;
    }

    if (tree->size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    __binary_search_tree_post_order(tree->root);
    printf("\b\b]\n");
}

void binary_search_tree_level_order(binary_search_tree_t *tree) {
    if (tree == NULL) {
        return;
    }

    if (tree->size == 0) {
        printf("[]\n");
        return;
    }

    queue_t *queue = queue_create();
    queue_enqueue(queue, tree->root);

    printf("[");
    while (!queue_is_empty(queue)) {
        node_t *node = queue_dequeue(queue);
        printf("%d, ", node->data);

        if (node->left != NULL) {
            queue_enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            queue_enqueue(queue, node->right);
        }
    }
    printf("\b\b]\n");

    queue_destroy(queue);
}