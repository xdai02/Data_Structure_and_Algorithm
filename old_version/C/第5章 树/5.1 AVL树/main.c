#include <stdio.h>
#include "avl_tree.h"

int main() {
	int arr[] = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	AVLTree *root = NULL;
	for(int i = 0; i < n; i++) {
		root = insert(root, arr[i]);
	}

	printf("preOrder: ");
	preOrder(root);
	printf("\n");

	printf("inOrder: ");
	inOrder(root);
	printf("\n");

	printf("postOrder: ");
	postOrder(root);
	printf("\n");

	printTree(root, 0, "");
	destroyAVLTree(root);
	return 0;
}
