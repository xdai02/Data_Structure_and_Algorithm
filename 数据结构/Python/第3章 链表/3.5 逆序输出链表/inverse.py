import node
import linked_list
import stack

def inverse(node):
    if node:
        inverse(node.next)
        print(node.data, end=' ')

def inverse_non_recursive(lst):
    s = stack.Stack()

    node = lst.get_head()
    while node:
        s.push(node)
        node = node.next
    while not s.is_empty():
        print(s.pop().data, end=' ')
    print()

def main():
    lst = linked_list.LinkedList()

    n = 6
    for i in range(n):
        lst.insert(i, node.Node(i))
    
    inverse(lst.get_head())
    print()

    inverse_non_recursive(lst)

if __name__ == "__main__":
    main()