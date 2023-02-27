class MinHeap:
    def __init__(self, elements=[]):
        self.__data = elements
        self.__heapify()
    
    def __len__(self):
        return len(self.__data)

    def is_empty(self):
        return len(self.__data) == 0
    
    def clear(self):
        self.__data = []
    
    def __heapify(self):
        for i in range(len(self.__data) // 2 - 1, -1, -1):
            self.__sift_down(i)

    def __sift_up(self, index):
        parent_index = (index - 1) // 2
        while parent_index >= 0 and self.__data[parent_index] > self.__data[index]:
            self.__data[index], self.__data[parent_index] = self.__data[parent_index], self.__data[index]
            index = parent_index
            parent_index = (index - 1) // 2

    def __sift_down(self, index):
        child_index = 2 * index + 1
        while child_index < len(self.__data):
            if child_index + 1 < len(self.__data) and self.__data[child_index + 1] < self.__data[child_index]:
                child_index += 1
            if self.__data[index] <= self.__data[child_index]:
                break
            self.__data[index], self.__data[child_index] = self.__data[child_index], self.__data[index]
            index = child_index
            child_index = 2 * index + 1

    def push(self, elem):
        self.__data.append(elem)
        self.__sift_up(len(self.__data) - 1)

    def pop(self):
        if self.is_empty():
            raise IndexError("Heap is empty")
        
        self.__data[0], self.__data[-1] = self.__data[-1], self.__data[0]
        elem = self.__data.pop()
        self.__sift_down(0)
        return elem

    def peek(self):
        if self.is_empty():
            raise IndexError("Heap is empty")
        return self.__data[0]

class MaxHeap:
    def __init__(self, elements=[]):
        self.__data = elements
        self.__heapify()
    
    def __len__(self):
        return len(self.__data)

    def is_empty(self):
        return len(self.__data) == 0
    
    def clear(self):
        self.__data = []
    
    def __heapify(self):
        for i in range(len(self.__data) // 2 - 1, -1, -1):
            self.__sift_down(i)

    def __sift_up(self, index):
        parent_index = (index - 1) // 2
        while parent_index >= 0 and self.__data[parent_index] < self.__data[index]:
            self.__data[index], self.__data[parent_index] = self.__data[parent_index], self.__data[index]
            index = parent_index
            parent_index = (index - 1) // 2
    
    def __sift_down(self, index):
        child_index = 2 * index + 1
        while child_index < len(self.__data):
            if child_index + 1 < len(self.__data) and self.__data[child_index + 1] > self.__data[child_index]:
                child_index += 1
            if self.__data[index] >= self.__data[child_index]:
                break
            self.__data[index], self.__data[child_index] = self.__data[child_index], self.__data[index]
            index = child_index
            child_index = 2 * index + 1
    
    def push(self, elem):
        self.__data.append(elem)
        self.__sift_up(len(self.__data) - 1)
    
    def pop(self):
        if self.is_empty():
            raise IndexError("Heap is empty")
        
        self.__data[0], self.__data[-1] = self.__data[-1], self.__data[0]
        elem = self.__data.pop()
        self.__sift_down(0)
        return elem
    
    def peek(self):
        if self.is_empty():
            raise IndexError("Heap is empty")
        return self.__data[0]