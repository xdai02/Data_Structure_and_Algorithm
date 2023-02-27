class Queue:
    def __init__(self):
        self.__data = []
    
    def is_empty(self):
        return self.__data == []
    
    def __len__(self):
        return len(self.__data)
    
    def clear(self):
        self.__data = []
    
    def enqueue(self, elem):
        self.__data.append(elem)
    
    def dequeue(self):
        return self.__data.pop(0)
    
    def front(self):
        return self.__data[0]