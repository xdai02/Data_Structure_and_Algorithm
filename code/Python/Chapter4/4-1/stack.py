class Stack:
    def __init__(self):
        self.__data = []
    
    def is_empty(self):
        return self.__data == []
    
    def size(self):
        return len(self.__data)
    
    def push(self, data):
        self.__data.append(data)
    
    def pop(self):
        return self.__data.pop()
    
    def peek(self):
        return self.__data[-1]