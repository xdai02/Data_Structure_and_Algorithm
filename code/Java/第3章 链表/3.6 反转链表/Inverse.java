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
    }

    public static void inverse(Node head) {
        if(head != null) {
            inverse(head.next);
            System.out.print(head.data + " ");
        }
    }
}
