import java.util.LinkedList;

public class SinglyLinkedList {
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		
		list.add(1);				// [1]
		list.add(0, 2);				// [2, 1]
		list.add(2, 3);				// [2, 1, 3]
		System.out.println(list);
		
		list.remove(0);				// [1, 3]
		list.add(1, 4);				// [1, 4, 3]
		list.remove(2);				// [1, 4]
		System.out.println(list);
		
		list.set(0, 5);				// [5, 4]
		list.set(1, 6);				// [5, 6]
		System.out.println(list);
		
		System.out.println(list.get(1));	// 6
	}
}
