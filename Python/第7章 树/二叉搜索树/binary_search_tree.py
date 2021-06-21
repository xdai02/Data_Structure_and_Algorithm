class Node:
    """
        结点类
    """
    def __init__(self, data, left=None, right=None):
        """
            初始化结点
            Args:
                data (int): 结点元素
                left (Node): 左孩子
                right (Node): 右孩子
        """
        self.data = data
        self.left = left
        self.right = right

class BinarySearchTree:
    """
        二叉搜索树
    """
    SPACES = 4

    def __init__(self, val):
        """
            初始化二叉树
            Args:
                data (int): 树根元素
        """
        self.root = Node(val)
    
    def pre_order(self, node):
        """
            先序遍历
            Args:
                node (Node): 树根
        """
        if node == None:
            return
        print(node.data, end=' ')
        self.pre_order(node.left)
        self.pre_order(node.right)
    
    def in_order(self, node):
        """
            中序遍历
            Args:
                node (Node): 树根
        """
        if node == None:
            return
        self.in_order(node.left)
        print(node.data, end=' ')
        self.in_order(node.right)
    
    def post_order(self, node):
        """
            后序遍历
            Args:
                node (Node): 树根
        """
        if node == None:
            return
        self.post_order(node.left)
        self.post_order(node.right)
        print(node.data, end=' ')
    
    def indent(self, level):
        """
            打印表示层次的空格符
            Args:
                level (int): 二叉树层次
        """
        for _ in range(self.SPACES * level):
            print(".", end='')
    
    def show_tree(self, node, level):
        """
            树状打印二叉树
            Args:
                node (Node): 树根
                level (int): 二叉树层次
        """
        if node == None:
            return
        self.indent(level)
        print(node.data)
        level += 1
        self.show_tree(node.left, level)
        self.show_tree(node.right, level)
        level -= 1
    
    def insert(self, node, val):
        """
            插入元素
            Args:
                node (Node): 树根
                val (int): 插入值
            Returns:
                [Node]: 操作后树根结点
        """
        # 空树，插入结点设为树根
        if node == None:
            return Node(val)
        
        if val < node.data:
            node.left = self.insert(node.left, val)
        else:
            node.right = self.insert(node.right, val)
        return node
    
    def search(self, node, val):
        """
            查找元素
            Args:
                node (Node): 树根
                val (int): 查找元素
            Returns:
                [Node]: 元素所在结点指针，不存在返回None
        """
        if node == None:
            return None
        
        if val == node.data:
            return node
        elif val < node.data:
            return self.search(node.left, val)
        else:
            return self.search(node.right, val)
    
    def get_height(self, node):
        """
            获取树高
            Args:
                node (Node): 树根
            Returns:
                [int]: 树高
        """
        if node == None:
            return 0
        return max(self.get_height(node.left), self.get_height(node.right)) + 1

def main():
    bst = BinarySearchTree(5)

    bst.insert(bst.root, 2)
    bst.insert(bst.root, 7)
    bst.insert(bst.root, 4)
    bst.insert(bst.root, 9)
    bst.insert(bst.root, 1)
    bst.insert(bst.root, 6)
    bst.insert(bst.root, 8)
    bst.insert(bst.root, 3)

    print("preOrder: ", end='')
    bst.pre_order(bst.root)
    print()

    print("inOrder: ", end='')
    bst.in_order(bst.root)
    print()

    print("postOrder: ", end='')
    bst.post_order(bst.root)
    print()

    bst.show_tree(bst.root, 0)
    print("height: %d" % bst.get_height(bst.root))

if __name__ == "__main__":
    main()