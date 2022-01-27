import node
import linked_list

def find_last_kth(linked_list, k):
    p1 = linked_list.get_head()
    p2 = linked_list.get_head()

    i = 0
    while p2 and i < k:
        p2 = p2.next
        i += 1
    
    while p2:
        p1 = p1.next
        p2 = p2.next
    
    return p1

def main():
    lst = linked_list.LinkedList()

    n = 6
    for i in range(n):
        lst.insert(i, node.Node(i))
    
    # [0, 1, 2, 3, 4, 5]
    print(find_last_kth(lst, 3).data)

if __name__ == "__main__":
    main()