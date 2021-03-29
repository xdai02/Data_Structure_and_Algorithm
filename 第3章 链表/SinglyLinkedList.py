class Node:
    """
        链表结点
    """
    def __init__(self, data):
        """
            初始化结点
            @data - 结点元素
        """
        self.data = data    # 数据域
        self.next = None    # 指针域
        
class SinglyLinkedList:
    """
        单链表
    """
    def __init__(self):
        """
            初始化链表，头结点为None
        """
        self.__head = None
    
    def is_empty(self):
        """
            判断是否为空链表
            @return - 空=True，非空=False
        """
        return self.__head == None
    
    def get_length(self):
        """
            计算链表长度
            @return - 链表元素个数
        """
        cnt = 0
        cur = self.__head
        # 遍历链表
        while cur != None:
            cnt += 1
            cur = cur.next
        return cnt
    
    def iterator(self):
        """
            链表迭代器
        """
        cur = self.__head
        while cur != None:
            yield cur.data
            cur = cur.next
    
    def __str__(self):
        """
            遍历链表
            @return - 链表元素
        """
        return str([data for data in self.iterator()])

    def insert_front(self, data):
        """
            插入到链表头部
            @data - 插入元素
        """
        node = Node(data)   # 创建结点
        node.next = self.__head
        self.__head = node
    
    def append(self, data):
        """
            追加元素到链表尾部
            @data - 追加元素
        """
        node = Node(data)   # 创建结点
        
        # 如果是空链表，新结点设为头结点
        if self.is_empty():
            self.__head = node
        # 不是空链表，找到链表尾部
        else:
            cur = self.__head
            while cur.next != None:
                cur = cur.next
            cur.next = node
    
    def insert(self, pos, data):
        """
            插入元素到链表
            @pos - 插入位置下标
            @data - 插入元素
        """
        # 指定位置在第一个元素之前，进行头部插入
        if pos <= 0:
            self.insert_front(data)
        # 指定位置超过尾部，进行尾部追加
        elif pos > self.get_length() - 1:
            self.append(data)
        else:
            node = Node(data)   # 创建结点
            cur = self.__head
            # 找到插入位置
            for _ in range(pos - 1):
                cur = cur.next
            node.next = cur.next
            cur.next = node
    
    def remove(self, data):
        """
            删除结点
            @data - 需删除元素
            @return - 删除成功=True，删除失败=False
        """
        cur = self.__head
        pre = None      # 指向前一个结点

        while cur != None:
            # 找到指定元素
            if cur.data == data:
                # 如果第一个就是需删除的结点
                if not pre:
                    # 将头指针指向头结点的下一个结点
                    self.__head = cur.next
                    return True
                else:
                    # 将删除位置前一个结点的next指向删除位置的后一个结点
                    pre.next = cur.next
                    return True
            else:
                # 继续向后查找
                pre = cur
                cur = cur.next
        return False

    def find(self, data):
        """
            查找元素
            @data - 被查找元素
            @return - 找到=True，未找到=False
        """
        return data in self.iterator()

def main():
    lst = SinglyLinkedList()

    lst.append(1)           # [1]
    lst.insert_front(2)     # [2, 1]
    lst.insert(2, 3)        # [2, 1, 3]
    print(lst)

    lst.remove(2)           # [1, 3]
    lst.insert(1, 4)        # [1, 4, 3]
    lst.remove(3)           # [1, 4]
    print(lst)

    print(lst.find(4))      # True

if __name__ == "__main__":
    main()