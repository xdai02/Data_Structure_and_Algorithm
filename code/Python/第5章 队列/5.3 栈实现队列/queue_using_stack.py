class Queue:
    def __init__(self):
        self.in_stack = list()
        self.out_stack = list()
    
    def is_empty(self):
        return not self.in_stack and not self.out_stack

    def enqueue(self, data):
        self.in_stack.append(data)
    
    def dequeue(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        return self.out_stack.pop()

def main():
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    while not q.is_empty():
        print(q.dequeue())

if __name__ == "__main__":
    main()