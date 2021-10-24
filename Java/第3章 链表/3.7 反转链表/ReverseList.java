public class ReverseList {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        int n = 6;
        for(int i = 0; i < n; i++) {
            list.insert(i, new Node(i));
        }

        // recursive
        Node newHead = reverseList(list.getHead());
        LinkedList reversedList = new LinkedList();
        int i = 0;
        while(newHead != null) {
            reversedList.insert(i, new Node(newHead.data));
            i++;
            newHead = newHead.next;
        }
        reversedList.show();

        // iterative
//        Node newHead = reverseListIterative(list);
//        LinkedList reversedList = new LinkedList();
//        int i = 0;
//        while(newHead != null) {
//            reversedList.insert(i, new Node(newHead.data));
//            i++;
//            newHead = newHead.next;
//        }
//        reversedList.show();
    }

    public static Node reverseList(Node head) {
        if(head == null || head.next == null) {
            return head;
        }
        Node next = head.next;
        head.next = null;
        Node newHead = reverseList(next);
        next.next = head;
        return newHead;
    }

    public static Node reverseListIterative(LinkedList list) {
        Node newHead = new Node(-1);
        Node head = list.getHead();
        while(head != null) {
            Node next = head.next;
            head.next = newHead.next;
            newHead.next = head;
            head = next;
        }
        return newHead.next;
    }
}
