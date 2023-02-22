class BinarySearchTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.__root = None
        self.__size = 0
    
    def is_empty(self):
        return self.__root is None
    
    def __len__(self):
        return self.__size
    
    def height(self):
        return self.__height(self.__root)
    
    def __height(self, node):
        if node is None:
            return 0
        return max(self.__height(node.left), self.__height(node.right)) + 1

    def clear(self):
        self.__root = None
        self.__size = 0

    def contains(self, data):
        node = self.__root
        while node is not None:
            if data < node.data:
                node = node.left
            elif data > node.data:
                node = node.right
            else:
                return True
        return False
    
    def add(self, data):
        self.__root = self.__add(self.__root, data)
    
    def __add(self, node, data):
        if node is None:
            self.__size += 1
            return self.Node(data)
        if data < node.data:
            node.left = self.__add(node.left, data)
        elif data > node.data:
            node.right = self.__add(node.right, data)
        return node
    
    def remove(self, data):
        self.__root = self.__remove(self.__root, data)
    
    def __remove(self, node, data):
        if node is None:
            return None
        if data < node.data:
            node.left = self.__remove(node.left, data)
        elif data > node.data:
            node.right = self.__remove(node.right, data)
        else:
            if node.left is None:
                self.__size -= 1
                return node.right
            elif node.right is None:
                self.__size -= 1
                return node.left
            else:
                node.data = self.__min(node.right)
                node.right = self.__remove(node.right, node.data)
        return node

    def __min(self, node):
        while node.left is not None:
            node = node.left
        return node.data
    
    def __max(self, node):
        while node.right is not None:
            node = node.right
        return node.data

    def pre_order(self):
        for node in self.__pre_order(self.__root):
            yield node.data
    
    def __pre_order(self, node):
        if node is not None:
            yield node
            yield from self.__pre_order(node.left)
            yield from self.__pre_order(node.right)
        
    def in_order(self):
        for node in self.__in_order(self.__root):
            yield node.data

    def __in_order(self, node):
        if node is not None:
            yield from self.__in_order(node.left)
            yield node
            yield from self.__in_order(node.right)

    def post_order(self):
        for node in self.__post_order(self.__root):
            yield node.data

    def __post_order(self, node):
        if node is not None:
            yield from self.__post_order(node.left)
            yield from self.__post_order(node.right)
            yield node

    def __str__(self):
        return "[" + ", ".join(str(node.data) for node in self.in_order()) + "]"

    def __iter__(self):
        return self.in_order()