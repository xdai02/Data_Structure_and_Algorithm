import node
import linked_list
import stack

def inverse(node):
    if node:
        inverse(node.next)
        print(node.data, end=' ')

def main():
    lst = linked_list.LinkedList()

    n = 6
    for i in range(n):
        lst.insert(i, node.Node(i))
    
    inverse(lst.get_head())
    print()

if __name__ == "__main__":
    main()