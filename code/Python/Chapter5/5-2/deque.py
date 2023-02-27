class Deque:
    def __init__(self):
        self.__data = []
    
    def is_empty(self):
        return self.__data == []
    
    def __len__(self):
        return len(self.__data)
    
    def clear(self):
        self.__data = []
    
    def push_front(self, elem):
        self.__data.insert(0, elem)
    
    def push_back(self, elem):
        self.__data.append(elem)
    
    def pop_front(self):
        return self.__data.pop(0)
    
    def pop_back(self):
        return self.__data.pop()
    
    def front(self):
        return self.__data[0]
    
    def back(self):
        return self.__data[-1]