public class SinglyLinkedList {
	private Node head;		// ����ͷ���
	
	/**
	 * @brief  ��ʼ������
	 */
	public SinglyLinkedList() {
		this.head = null;
	}
	
	/**
	 * @brief  �ж��Ƿ��ǿ�����
	 * @retval ��������true��Ϊ��������false
	 */
	public boolean isEmpty() {
	    return this.head == null;
	}

	/**
	 * @brief  ��ȡ������
	 * @retval ������
	 */
	public int getLength() {
	    Node temp = this.head;
	    int len = 0;
	    while(temp != null) {
	    	len++;
	    	temp = temp.next;
	    }
	    return len;
	}
	
	/**
	 * @brief  ��ӡ����
	 */
	public void show() {
	    Node temp = this.head;
	    while(temp != null) {
	        System.out.print(temp.data + " ");
	    	temp = temp.next;
	    }
	    System.out.println();
	}
	
	/**
	 * ͷ��������
	 * @param val
	 */
	public void addFront(int val) {
		Node newNode = new Node(val);
		newNode.next = this.head;
		this.head = newNode;
	}
	
	/**
	 * @brief  ������
	 * @param  pos: ����λ��
	 * @param  val: ����Ԫ��
	 */
	public void insert(int pos, int val) {
	    // ��������Χ
	    if(pos < 0 || pos > getLength()) {
	        System.err.println("Error: position out of bound.");
	    	return;
		}
	    
	    // ͷ������
	    if(pos == 0) {
	    	addFront(val);
	    	return;
	    }
	    
	    // �ҵ�Ҫ�������ǰһ�����
	    Node temp = this.head;
	    for(int i = 0; i < pos - 1; i++) {
	    	temp = temp.next;
	    }
	    Node newNode = new Node(val);
	    newNode.next = temp.next;
	    temp.next = newNode;
	}
	
	/**
	 * @brief  ɾ�����
	 * @param  pos: ����λ��
	 */
	public void delete(int pos) {
	    // ��������Χ
	    if(pos < 0 || pos >= getLength()) {
	    	System.err.println("Error: position out of bound.");
			return;
		}
	    
	    // ɾ��ͷ���
	    if(pos == 0) {
	    	this.head = this.head.next;
	    	return;
	    }
	    
	    // �ҵ�ɾ��λ��
	    Node temp = this.head;
	    for(int i = 0; i < pos - 1; i++) {
	    	temp = temp.next;
	    }
	    temp.next = temp.next.next;
	}

	/**
	 * @brief  ����Ԫ��
	 * @param  val: ����ֵ
	 * @retval ���ؽ��ָ�룬δ�ҵ�����null
	 */
	public Node search(int val) {
	    // ����Ԫ��λ��
	    Node temp = this.head;
	    while(temp != null) {
	    	if(temp.data == val) {
	    		return temp;
	    	}
	        temp = temp.next;
	    }
	    return null;
	}

	/**
	 * @brief  �޸�Ԫ��
	 * @param  pos: �޸�λ��
	 * @param  val - ������
	 */
	public void set(int pos, int val) {
	    // ��������Χ
	    if(pos < 0 || pos >= getLength()) {
	    	System.err.println("Error: position out of bound.");
			return;
		}

	    // �ҵ�Ԫ��λ��
		Node temp = this.head;
	    for(int i = 0; i < pos; i++) {
	        temp = temp.next;
	    }
	    temp.data = val;
	}
	
	public static void main(String[] args) {
		SinglyLinkedList list = new SinglyLinkedList();
		
		list.insert(0, 1);			// [1]
		list.insert(0, 2);			// [2, 1]
		list.insert(2, 3);			// [2, 1, 3]
		list.show();
		
		list.delete(0);				// [1, 3]
		list.insert(1, 4);			// [1, 4, 3]
		list.delete(2);				// [1, 4]
		list.show();
		
		list.set(0, 5);				// [5, 4]
		list.set(1, 6);				// [5, 6]
		list.show();
		
		System.out.println(list.search(6).data);	// 6
	}
}
