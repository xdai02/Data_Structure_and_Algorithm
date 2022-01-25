class LinkedList:
    def __init__(self):
        self.__head = None

    def get_head(self):
        return self.__head
    
    def is_empty(self):
        return self.__head == None
    
    def get_length(self):
        cnt = 0
        cur = self.__head
        while cur:
            cnt += 1
            cur = cur.next
        return cnt
    
    def iterator(self):
        cur = self.__head
        while cur:
            yield cur.data
            cur = cur.next
    
    def __str__(self):
        return str([data for data in self.iterator()])

    def insert_front(self, node):
        node.next = self.__head
        self.__head = node
    
    def append(self, node):
        if self.is_empty():
            self.__head = node
        else:
            cur = self.__head
            while cur.next != None:
                cur = cur.next
            cur.next = node
    
    def insert(self, pos, node):
        if pos <= 0:
            self.insert_front(node)
        elif pos > self.get_length() - 1:
            self.append(node)
        else:
            cur = self.__head
            for _ in range(pos - 1):
                cur = cur.next
            node.next = cur.next
            cur.next = node
    
    def remove(self, pos):
        if pos < 0 or pos > self.get_length():
            return False
        cur = self.__head
        for _ in range(pos - 1):
            cur = cur.next
        cur.next = cur.next.next
        return True