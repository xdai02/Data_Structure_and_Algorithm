import node
import linked_list

def reverse_list(head):
    if not head or not head.next:
        return head
    next = head.next
    head.next = None
    new_head = reverse_list(next)
    next.next = head
    return new_head

def reverse_list_iterative(lst):
    new_head = node.Node(-1)
    head = lst.get_head()
    while head:
        next = head.next
        head.next = new_head.next
        new_head.next = head
        head = next
    return new_head.next

def main():
    n = 6
    lst = linked_list.LinkedList()
    nodes = []

    for i in range(n):
        nodes.append(node.Node(i))
        lst.insert(i, nodes[i])
    
    # recursive
    new_head = reverse_list(lst.get_head())
    reversed_list = linked_list.LinkedList()
    i = 0
    while new_head:
        reversed_list.insert(i, node.Node(new_head.data))
        i += 1
        new_head = new_head.next
    print(reversed_list)

    # iterative
    # new_head = reverse_list_iterative(lst)
    # reversed_list = linked_list.LinkedList()
    # i = 0
    # while new_head:
    #     reversed_list.insert(i, node.Node(new_head.data))
    #     i += 1
    #     new_head = new_head.next
    # print(reversed_list)

if __name__ == "__main__":
    main()