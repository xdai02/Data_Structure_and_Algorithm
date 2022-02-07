import avl_tree

def main():
    lst = [3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9]
    avl = avl_tree.AVLTree()
    for data in lst:
        avl.insert(data)
    
    print("preOrder: ", end='')
    avl.pre_order()
    print()

    print("inOrder: ", end='')
    avl.in_order()
    print()

    print("poseOrder: ", end='')
    avl.post_order()
    print()

    avl.print_tree()

if __name__ == "__main__":
    main()