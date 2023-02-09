class Queue:
    def __init__(self):
        self.__data = []
    
    def is_empty(self):
        return self.__data == []
    
    def __len__(self):
        return len(self.__data)
    
    def enqueue(self, data):
        self.__data.append(data)
    
    def dequeue(self):
        return self.__data.pop(0)