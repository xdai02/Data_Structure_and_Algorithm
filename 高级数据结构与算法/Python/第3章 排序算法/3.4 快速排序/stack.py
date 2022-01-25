class Stack:
    def __init__(self):
        self.__stack = []

    def is_empty(self):
        return self.__stack == []
    
    def size(self):
        return len(self.__stack)

    def push(self, data):
        self.__stack.append(data)

    def pop(self):
        return self.__stack.pop()

    def peek(self):
        return self.__stack[-1]