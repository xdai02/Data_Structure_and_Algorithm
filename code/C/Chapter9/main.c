#include "binary_search_tree.h"

int main() {
    binary_search_tree_t *tree = binary_search_tree_create();
    int arr[] = {5, 3, 6, 8, 4, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        binary_search_tree_add(tree, arr[i]);
    }

    binary_search_tree_in_order(tree);

    return 0;
}