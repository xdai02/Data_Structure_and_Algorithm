#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACES 4

typedef int dataType;

typedef struct AVLNode {
	dataType data;
	int height;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode, AVLTree;

int height(AVLTree *tree);

void preOrder(AVLTree *tree);

void inOrder(AVLTree *tree);

void postOrder(AVLTree *tree);

void printTree(AVLTree *tree, int level, char *type);

AVLNode* search(AVLTree *tree, dataType key);

AVLNode* insert(AVLTree *tree, dataType val);

AVLNode* delete(AVLTree *tree, dataType val);

void destroyAVLTree(AVLTree *tree);

#endif
