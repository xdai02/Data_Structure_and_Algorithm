public class SinglyLinkedList {
	private Node head;		// 链表头结点
	
	/**
	 * @brief  初始化链表
	 */
	public SinglyLinkedList() {
		this.head = null;
	}
	
	/**
	 * @brief  判断是否是空链表
	 * @retval 空链表返回true，为空链表返回false
	 */
	public boolean isEmpty() {
	    return this.head == null;
	}

	/**
	 * @brief  获取链表长度
	 * @retval 链表长度
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
	 * @brief  打印链表
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
	 * 头部插入结点
	 * @param val
	 */
	public void addFront(int val) {
		Node newNode = new Node(val);
		newNode.next = this.head;
		this.head = newNode;
	}
	
	/**
	 * @brief  插入结点
	 * @param  pos: 插入位置
	 * @param  val: 插入元素
	 */
	public void insert(int pos, int val) {
	    // 超出链表范围
	    if(pos < 0 || pos > getLength()) {
	        System.err.println("Error: position out of bound.");
	    	return;
		}
	    
	    // 头部插入
	    if(pos == 0) {
	    	addFront(val);
	    	return;
	    }
	    
	    // 找到要插入结点的前一个结点
	    Node temp = this.head;
	    for(int i = 0; i < pos - 1; i++) {
	    	temp = temp.next;
	    }
	    Node newNode = new Node(val);
	    newNode.next = temp.next;
	    temp.next = newNode;
	}
	
	/**
	 * @brief  删除结点
	 * @param  pos: 插入位置
	 */
	public void delete(int pos) {
	    // 超出链表范围
	    if(pos < 0 || pos >= getLength()) {
	    	System.err.println("Error: position out of bound.");
			return;
		}
	    
	    // 删除头结点
	    if(pos == 0) {
	    	this.head = this.head.next;
	    	return;
	    }
	    
	    // 找到删除位置
	    Node temp = this.head;
	    for(int i = 0; i < pos - 1; i++) {
	    	temp = temp.next;
	    }
	    temp.next = temp.next.next;
	}

	/**
	 * @brief  查找元素
	 * @param  val: 查找值
	 * @retval 返回结点指针，未找到返回null
	 */
	public Node search(int val) {
	    // 查找元素位置
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
	 * @brief  修改元素
	 * @param  pos: 修改位置
	 * @param  val - 新数据
	 */
	public void set(int pos, int val) {
	    // 超出链表范围
	    if(pos < 0 || pos >= getLength()) {
	    	System.err.println("Error: position out of bound.");
			return;
		}

	    // 找到元素位置
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
