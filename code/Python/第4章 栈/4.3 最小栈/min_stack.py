import math

class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = [math.inf]
    
    def push(self, data):
        self.stack.append(data)
        self.min_stack.append(min(data, self.min_stack[-1]))
    
    def pop(self):
        self.stack.pop()
        self.min_stack.pop()
    
    def peek(self):
        return self.stack[-1]
    
    def get_min(self):
        return self.min_stack[-1]

def main():
    min_stack = MinStack()

    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)

    print(min_stack.get_min())      # -3
    min_stack.pop()
    print(min_stack.peek())         # 0
    print(min_stack.get_min())      # -2

if __name__ == "__main__":
    main()