import java.util.ArrayList;

public class Inverse {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        int n = 6;
        for(int i = 0; i < n; i++) {
            list.insert(i, new Node(i));
        }

        inverse(list.getHead());
        System.out.println();

        inverseNonRecursive(list);
    }

    public static void inverse(Node head) {
        if(head != null) {
            inverse(head.next);
            System.out.print(head.data + " ");
        }
    }

    public static void inverseNonRecursive(LinkedList list) {
        Stack s = new Stack();

        Node node = list.getHead();
        while(node != null) {
            s.push(node);
            node = node.next;
        }
        while(!s.isEmpty()) {
            System.out.print(s.pop().data + " ");
        }
        System.out.println();
    }
}
