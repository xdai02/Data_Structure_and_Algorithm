import collections

class Stack:
    def __init__(self):
        self.queue = collections.deque()
    
    def is_empty(self):
        return not self.queue

    def push(self, data):
        n = len(self.queue)
        self.queue.append(data)
        for _ in range(n):
            self.queue.append(self.queue.popleft())
    
    def pop(self):
        return self.queue.popleft()
    
    def peek(self):
        return self.queue[0]

def main():
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    while not s.is_empty():
        print(s.pop())

if __name__ == "__main__":
    main()