#include <stdio.h>
#include <stdlib.h>
#define SPACES 4

typedef int dataType;

typedef struct Node {
    dataType data;          // ������
    struct Node *left;      // ����
    struct Node *right;     // �Һ���
} Node, BST;

/**
 * @brief  ��ʼ��������
 * @param  val: ��Ԫ��
 * @retval ����ָ��
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
 * @brief  �������
 * @param  root: ����
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
 * @brief  �������
 * @param  root: ����
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
 * @brief  �������
 * @param  root: ����
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
 * @brief  ��ӡ��ʾ��εĿո��
 * @note   ������״��ӡ������
 * @param  level: ���������
 */
void indent(int level) {
    for(int i = 0; i < SPACES * level; i++) {
        printf(".");
    }
}

/**
 * @brief  ��״��ӡ������
 * @param  root: ����
 * @param  level: ���������
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
 * @brief  ����Ԫ��
 * @param  root: ����
 * @param  val: ����ֵ
 * @retval ����������ָ��
 */
BST* insert(BST *root, dataType val) {
    // ��������������Ϊ����
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
 * @brief  ����Ԫ��
 * @param  root: ����
 * @param  val: ����Ԫ��
 * @retval Ԫ�����ڽ��ָ�룬�����ڷ���NULL
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
 * @brief  ���ٶ�����
 * @param  root: ����
 */
void destroyBST(BST *root) {
    // ������ֱ�ӷ���
    if(!root) {
        return;
    }

    // �ݹ��ͷ���������
    if(!root->left && !root->right) {
        free(root);
        root = NULL;
    } else if(root->left) {
        destroyBST(root->left);
    } else {
        destroyBST(root->right);
    }
    // �ͷŸ����
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
