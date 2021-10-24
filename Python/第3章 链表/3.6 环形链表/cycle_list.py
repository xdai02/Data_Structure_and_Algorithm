import node
import linked_list

def cycle_node(linked_list):
    p1 = linked_list.get_head()
    p2 = linked_list.get_head()

    while p1 and p2:
        if not p2.next or not p2.next.next:
            return None
        p1 = p1.next
        p2 = p2.next.next
        if p1 == p2:
            return p1
    return None

def cycle_length(linked_list):
    node = cycle_node(linked_list)
    if not node:
        return 0
    len = 1
    cur = node.next
    while cur != node:
        cur = cur.next
        len += 1
    return len

def cycle_entrance(linked_list):
    n = cycle_length(linked_list)
    if n == 0:
        return None
    
    p1 = linked_list.get_head()
    p2 = linked_list.get_head()
    for _ in range(n):
        p2 = p2.next

    while p1 != p2:
        p1 = p1.next
        p2 = p2.next
    return p1

def main():
    n = 6
    lst = linked_list.LinkedList()
    nodes = []

    for i in range(n):
        nodes.append(node.Node(i))
        lst.insert(i, nodes[i])
    
    cur = lst.get_head()
    for _ in range(n - 1):
        cur = cur.next
    cur.next = nodes[2]
    
    """
        0 → 1 → 2 → 3 → 4 → 5
                ↑           ↓
                ←  ←  ←  ←  ←
    """
    print("contains cycle:", cycle_node(lst) != None)
    print("cycle length:", cycle_length(lst))
    print("cycle entrance:", cycle_entrance(lst).data)

if __name__ == "__main__":
    main()