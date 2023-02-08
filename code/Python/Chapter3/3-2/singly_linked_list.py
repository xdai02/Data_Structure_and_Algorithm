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
    
    def __len__(self):
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
    
    def set(self, index, data):
        if index < 0 or index >= self.__len:
            raise IndexError("Index out of range")

        cur = self.__head
        for _ in range(index):
            cur = cur.next
        cur.data = data
    
    def __str__(self):
        cur = self.__head
        s = "["
        while cur != None:
            s += str(cur.data)
            if cur.next != None:
                s += ", "
            cur = cur.next
        s += "]"
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
    
    def __reverse_recursive(self, node):
        if node == None or node.next == None:
            return node

        new_head = self.__reverse_recursive(node.next)
        node.next.next = node
        node.next = None
        return new_head

    def reverse_recursive(self):
        self.__head = self.__reverse_recursive(self.__head)

    def reverse(self):
        if self.__head == None or self.__head.next == None:
            return

        cur = self.__head
        pre = None
        while cur != None:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        self.__head = pre