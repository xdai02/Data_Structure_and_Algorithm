#include <stdio.h>
#include <stdlib.h>
#define SPACES 4

typedef int dataType;

typedef struct Node {
    dataType data;          // 数据域
    struct Node *left;      // 左孩子
    struct Node *right;     // 右孩子
} Node, BST;

/**
 * @brief  初始化二叉树
 * @param  val: 根元素
 * @retval 树根指针
 */
BST* init(dataType val) {
    BST *root = (BST *)malloc(sizeof(BST));
    if(!root) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

/**
 * @brief  先序遍历
 * @param  root: 树根
 */
void preOrder(BST *root) {
    if(!root) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

/**
 * @brief  中序遍历
 * @param  root: 树根
 */
void inOrder(BST *root) {
    if(!root) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

/**
 * @brief  后序遍历
 * @param  root: 树根
 */
void postOrder(BST *root) {
    if(!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

/**
 * @brief  打印表示层次的空格符
 * @note   用于树状打印二叉树
 * @param  level: 二叉树层次
 */
void indent(int level) {
    for(int i = 0; i < SPACES * level; i++) {
        printf(".");
    }
}

/**
 * @brief  树状打印二叉树
 * @param  root: 树根
 * @param  level: 二叉树层次
 */
void showTree(BST *root, int level) {
    if(!root) {
        return;
    }
    indent(level);
    printf("%d\n", root->data);
    level++;
    showTree(root->left, level);
    showTree(root->right, level);
    level--;
}

/**
 * @brief  插入元素
 * @param  root: 树根
 * @param  val: 插入值
 * @retval 操作后树根指针
 */
BST* insert(BST *root, dataType val) {
    // 空树，插入结点设为树根
    if(!root) {
        return init(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else if(val >= root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief  查找元素
 * @param  root: 树根
 * @param  val: 查找元素
 * @retval 元素所在结点指针，不存在返回NULL
 */
Node* search(Node *root, dataType val) {
    if(!root) {
        return NULL;
    }

    if(val == root->data) {
        return root;
    } else if(val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

/**
 * @brief  销毁二叉树
 * @param  root: 树根
 */
void destroyBST(BST *root) {
    // 空树，直接返回
    if(!root) {
        return;
    }

    // 递归释放左右子树
    if(!root->left && !root->right) {
        free(root);
        root = NULL;
    } else if(root->left) {
        destroyBST(root->left);
    } else {
        destroyBST(root->right);
    }
    // 释放根结点
    free(root);
    root = NULL;
}

int main() {
    BST *root = init(5);
    
    insert(root, 2);
    insert(root, 7);
    insert(root, 4);
    insert(root, 9);
    insert(root, 1);
    insert(root, 6);
    insert(root, 8);
    insert(root, 3);

    printf("preOrder: ");
    preOrder(root);
    printf("\n");
	
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
	
    printf("postOrder: ");
    postOrder(root);
    printf("\n");

    showTree(root, 0);

    destroyBST(root);
    return 0;
}
