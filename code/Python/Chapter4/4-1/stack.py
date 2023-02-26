class Stack:
    def __init__(self):
        self.__data = []
    
    def is_empty(self):
        return self.__data == []
    
    def __len__(self):
        return len(self.__data)
    
    def push(self, elem):
        self.__data.append(elem)
    
    def pop(self):
        return self.__data.pop()
    
    def peek(self):
        return self.__data[-1]