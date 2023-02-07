class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__len = 0
    
    def is_empty(self):
        return self.__head == None
    
    def length(self):
        return self.__len
    
    def add(self, data):
        node = Node(data)
        if self.is_empty():
            self.__head = node
        else:
            self.__tail.next = node
        self.__tail = node
        self.__len += 1
    
    def insert(self, index, data):
        if index < 0 or index > self.__len:
            raise IndexError("Index out of range")

        node = Node(data)
        if index == 0:
            node.next = self.__head
            self.__head = node
        else:
            cur = self.__head
            for _ in range(index - 1):
                cur = cur.next
            node.next = cur.next
            cur.next = node
        self.__len += 1
    
    def remove(self, index):
        if index < 0 or index >= self.__len:
            raise IndexError("Index out of range")

        if index == 0:
            data = self.__head.data
            self.__head = self.__head.next
        else:
            cur = self.__head
            for _ in range(index - 1):
                cur = cur.next
            data = cur.next.data
            cur.next = cur.next.next
        self.__len -= 1
        return data
    
    def get(self, index):
        if index < 0 or index >= self.__len:
            raise IndexError("Index out of range")

        cur = self.__head
        for _ in range(index):
            cur = cur.next
        return cur.data
    
    def __str__(self):
        cur = self.__head
        s = ""
        while cur != None:
            s += str(cur.data) + " "
            cur = cur.next
        return s
    
    def __iter__(self):
        self.__cur = self.__head
        return self
    
    def __next__(self):
        if self.__cur == None:
            raise StopIteration
        data = self.__cur.data
        self.__cur = self.__cur.next
        return data