class Node:
    """
        结点类
    """
    def __init__(self, data):
        """
            初始化结点
            @data - 结点元素
        """
        self.data = data

class Stack:
    """
        顺序栈
    """
    def __init__(self):
        """
            初始化栈
        """
        self.__stack = []

    def is_empty(self):
        """
            判断是否为空栈
            @return - 空栈=True，非空栈=False
        """
        return self.__stack == []
    
    def size(self):
        """
            获取栈中元素个数
            @return - 栈元素个数
        """
        return len(self.__stack)

    def push(self, data):
        """
            入栈
            @data - 入栈元素
        """
        self.__stack.append(data)

    def pop(self):
        """
            出栈
            @return - 出栈元素
        """
        return self.__stack.pop()

    def peek(self):
        """
            取栈顶
            @return - 栈顶元素
        """
        return self.__stack[-1]

def main():
    s = Stack()

    s.push(1)               # 底 [1] 顶
    s.push(2)               # 底 [1, 2] 顶
    s.push(3)               # 底 [1, 2, 3] 顶
    print(s.peek())         # 3

    while not s.is_empty():
        print(s.pop())

if __name__ == "__main__":
    main()