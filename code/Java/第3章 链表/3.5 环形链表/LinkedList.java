public class LinkedList {
	private Node head;

	public LinkedList() {
		this.head = null;
	}

	public Node getHead() {
		return this.head;
	}

	public boolean isEmpty() {
	    return this.head == null;
	}

	public int getLength() {
	    Node cur = this.head;
	    int len = 0;
	    while(cur != null) {
	    	len++;
			cur = cur.next;
	    }
	    return len;
	}

	public void show() {
	    Node cur = this.head;
	    while(cur != null) {
	        System.out.print(cur.data + " ");
			cur = cur.next;
	    }
	    System.out.println();
	}

	public void addFront(Node node) {
		node.next = this.head;
		this.head = node;
	}

	public void insert(int pos, Node node) {
	    if(pos <= 0) {
			addFront(node);
	    	return;
		}

	    Node cur = this.head;
	    for(int i = 0; i < pos - 1; i++) {
			cur = cur.next;
	    }
	    node.next = cur.next;
		cur.next = node;
	}

	public void remove(int pos) {
	    if(pos < 0 || pos >= getLength()) {
	    	return;
		}

	    if(pos == 0) {
	    	this.head = this.head.next;
	    	return;
	    }

	    Node cur = this.head;
	    for(int i = 0; i < pos - 1; i++) {
			cur = cur.next;
	    }
		cur.next = cur.next.next;
	}
}
