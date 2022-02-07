#include "avl_tree.h"

static int max(int a, int b) {
	return a > b ? a : b;
}

int height(AVLTree *tree) {
	if(!tree) {
		return 0;
	}
	return tree->height;
}

void preOrder(AVLTree *tree) {
	if(tree) {
		printf("%d ", tree->data);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(AVLTree *tree) {
	if(tree) {
		inOrder(tree->left);
		printf("%d ", tree->data);
		inOrder(tree->right);
	}
}

void postOrder(AVLTree *tree) {
	if(tree) {
		postOrder(tree->left);
		postOrder(tree->right);
		printf("%d ", tree->data);
	}
}

static void indent(int level) {
	for(int i = 0; i < level * SPACES; i++) {
		printf(" ");
	}
}

void printTree(AVLTree *tree, int level, char *type) {
	if(tree) {
		indent(level);
		level++;
		printf("|__ %d%s\n", tree->data, type);
		printTree(tree->left, level, "L");
		printTree(tree->right, level, "R");
	}
}

AVLNode* search(AVLTree *tree, dataType key) {
	while(tree && tree->data != key) {
		if(key < tree->data) {
			tree = tree->left;
		} else {
			tree = tree->right;
		}
	}
	return tree;
}

static AVLNode* getMin(AVLTree *tree) {
	if(!tree) {
		return NULL;
	}
	while(tree->left) {
		tree = tree->left;
	}
	return tree;
}

static AVLNode* getMax(AVLTree *tree) {
	if(!tree) {
		return NULL;
	}
	while(tree->right) {
		tree = tree->right;
	}
	return tree;
}

static AVLNode* LLRotation(AVLTree *k2) {
	AVLTree *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}

static AVLNode* RRRotation(AVLTree *k1) {
	AVLTree *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(k1->height, height(k2->right)) + 1;
	return k2;
}

static AVLNode* LRRotation(AVLTree *k3) {
	k3->left = RRRotation(k3->left);
	return LLRotation(k3);
}

static AVLNode* RLRotation(AVLTree *k1) {
	k1->right = LLRotation(k1->right);
	return RRRotation(k1);
}

static AVLNode* createNode(dataType val, AVLNode *left, AVLNode *right) {
	AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
	node->data = val;
	node->height = 0;
	node->left = left;
	node->right = right;
	return node;
}

AVLNode* insert(AVLTree *tree, dataType val) {
	if(!tree) {
		tree = createNode(val, NULL, NULL);
		tree->height = 1;
		return tree;
	}

	if(val < tree->data) {
		tree->left = insert(tree->left, val);
		if(height(tree->left) - height(tree->right) == 2) {
			if(val < tree->left->data) {
				tree = LLRotation(tree);
			} else {
				tree = LRRotation(tree);
			}
		}
	} else {
		tree->right = insert(tree->right, val);
		if(height(tree->right) - height(tree->left) == 2) {
			if(val > tree->right->data) {
				tree = RRRotation(tree);
			} else {
				tree = RLRotation(tree);
			}
		}
	}

	tree->height = max(height(tree->left), height(tree->right)) + 1;
	return tree;
}

static AVLNode* deleteNode(AVLTree *tree, AVLNode *del) {
	if(!tree || !del) {
		return NULL;
	}

	if(del->data < tree->data) {
		tree->left = deleteNode(tree->left, del);
		if(height(tree->right) - height(tree->left) == 2) {
			AVLNode *rightNode = tree->right;
			if(height(rightNode->left) > height(rightNode->right)) {
				tree = RLRotation(tree);
			} else {
				tree = RRRotation(tree);
			}
		}
	} else if(del->data > tree->data) {
		tree->right = deleteNode(tree->right, del);
		if(height(tree->left) - height(tree->right) == 2) {
			AVLNode *leftNode = tree->left;
			if(height(leftNode->right) > height(leftNode->left)) {
				tree = LRRotation(tree);
			} else {
				tree = LLRotation(tree);
			}
		}
	} else {
		if(tree->left && tree->right) {
			if(height(tree->left) > height(tree->right)) {
				// 如果左子树比右子树高：
				// 1. 找出左子树的最大结点
				// 2. 将最大结点的值赋给tree
				// 3. 删除最大结点
				AVLNode *max = getMax(tree->left);
				tree->data = max->data;
				tree->left = deleteNode(tree->left, max);
			} else {
				// 如果右子树比左子树高（或相等）：
				// 1. 找出右子树的最小结点
				// 2. 将最小结点的值赋给tree
				// 3. 删除最小结点
				AVLNode *min = getMin(tree->right);
				tree->data = min->data;
				tree->right = deleteNode(tree->right, min);
			}
		} else {
			AVLNode *temp = tree;
			tree = tree->left ? tree->left : tree->right;
			free(temp);
		}
	}
	return tree;
}

AVLNode* delete(AVLTree *tree, dataType key) {
	AVLNode *del = search(tree, key);
	if(del) {
		tree = deleteNode(tree, del);
	}
	return tree;
}

void destroyAVLTree(AVLTree *tree) {
	if(!tree) {
		return;
	}
	if(tree->left) {
		destroyAVLTree(tree->left);
	}
	if(tree->right) {
		destroyAVLTree(tree->right);
	}
	free(tree);
}
