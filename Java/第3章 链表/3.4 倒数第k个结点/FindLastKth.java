public class FindLastKth {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        int n = 6;
        for(int i = 0; i < n; i++) {
            list.insert(i, new Node(i));
        }

        System.out.println(findLastKth(list, 3).data);
    }

    public static Node findLastKth(LinkedList list, int k) {
        Node p1 = list.getHead();
        Node p2 = list.getHead();

        int i = 0;
        while(p2 != null && i < k) {
            p2 = p2.next;
            i++;
        }
        while(p2 != null) {
            p1 = p1.next;
            p2 = p2.next;
        }
        return p1;
    }
}
