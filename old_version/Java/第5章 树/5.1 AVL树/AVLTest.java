public class AVLTest {
    public static void main(String[] args) {
        int[] arr = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
        AVLTree<Integer> avl = new AVLTree<>();
        for(int i = 0; i < arr.length; i++) {
            avl.insert(arr[i]);
        }

        System.out.print("preOrder: ");
        avl.preOrder();
        System.out.println();

        System.out.print("inOrder: ");
        avl.inOrder();
        System.out.println();

        System.out.print("postOrder: ");
        avl.postOrder();
        System.out.println();

        avl.printTree();
    }
}
