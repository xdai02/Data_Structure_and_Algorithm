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

class Queue:
    """
        队列
    """
    def __init__(self):
        """
            初始化队列
        """
        self.__queue = []
    
    def is_empty(self):
        """
            判断是否为空队列
            @return - 空队列=True，非空队列=False
        """
        return self.__queue == []
    
    def size(self):
        """
            获取队列元素个数
            @return - 队列元素个数
        """
        return len(self.__queue)
    
    def enqueue(self, data):
        """
            入队
            @data - 入队元素
        """
        self.__queue.append(data)
    
    def dequeue(self):
        """
            出队
            @retuen - 出队元素
        """
        return self.__queue.pop(0)

def main():
    q = Queue()

    q.enqueue(1)        # 头 [1] 尾
    q.enqueue(2)        # 头 [1, 2] 尾
    q.enqueue(3)        # 头 [1, 2, 3] 尾
    q.enqueue(4)        # 头 [1, 2, 3, 4] 尾
    q.enqueue(5)        # 头 [1, 2, 3, 4, 5] 尾

    while not q.is_empty():
        print(q.dequeue())

if __name__ == "__main__":
    main()