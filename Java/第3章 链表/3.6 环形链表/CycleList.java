public class CycleList {
    public static void main(String[] args) {
        int n = 6;
        LinkedList list = new LinkedList();
        Node[] nodes = new Node[n];

        for(int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
            list.insert(i, nodes[i]);
        }

        Node node = list.getHead();
        for(int i = 0; i < n - 1; i++) {
            node = node.next;
        }
        node.next = nodes[2];

        /*
            0 → 1 → 2 → 3 → 4 → 5
                    ↑           ↓
                    ←  ←  ←  ←  ←
         */
        System.out.println("contains cycle: " + cycleNode(list) != null);
        System.out.println("cycle length: " + cycleLength(list));
        System.out.println("cycle entrance: " + cycleEntrance(list).data);
    }

    public static Node cycleNode(LinkedList list) {
        Node p1 = list.getHead();
        Node p2 = list.getHead();

        while(p1 != null && p2 != null) {
            if(p2.next == null || p2.next.next == null) {
                return null;
            }
            p1 = p1.next;
            p2 = p2.next.next;
            if(p1 == p2) {
                return p1;
            }
        }
        return null;
    }

    public static int cycleLength(LinkedList list) {
        Node node = cycleNode(list);
        if(node == null) {
            return 0;
        }
        int len = 1;
        Node cur = node.next;
        while(cur != node) {
            cur = cur.next;
            len++;
        }
        return len;
    }

    public static Node cycleEntrance(LinkedList list) {
        int n = cycleLength(list);
        if(n == 0) {
            return null;
        }

        Node p1 = list.getHead();
        Node p2 = list.getHead();
        for(int i = 0; i < n; i++) {
            p2 = p2.next;
        }

        while(p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }
        return p1;
    }
}
