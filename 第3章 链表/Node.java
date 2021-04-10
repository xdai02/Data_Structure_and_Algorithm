public class Node {
	public int data;		// Êı¾İÓò
	public Node next;		// Ö¸ÕëÓò
	
	public Node(int data) {
		this.data = data;
		this.next = null;
	}
	
	public Node(int data, Node next) {
		this.data = data;
		this.next = next;
	}
}
