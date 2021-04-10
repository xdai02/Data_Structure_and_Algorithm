public class CircularQueue {
	private int[] data;			// ������
	private int front;			// ��ͷ
	private int rear;			// ��β
	private int max;			// ��������
	
	/**
	 * @brief  ��ʼ������
	 * @note   ѭ��������Ҫ����һ����λ
	 */
	public CircularQueue() {
		this.max = 10;
		this.data = new int[max];
		this.front = this.rear = 0;
	}
	
	/**
	 * @brief  ��ʼ������
	 * @note   ѭ��������Ҫ����һ����λ
	 * @param  size: ��������
	 */
	public CircularQueue(int size) {
		this.max = size + 1;
		this.data = new int[max];
		this.front = this.rear = 0;
	}
	
	/**
	 * @brief  �ж϶����Ƿ�Ϊ��
	 * @retval �ն��з���true���ǿշ���false
	 */
	public boolean isEmpty() {
		return front == rear;
	}
	
	/**
	 * @brief  �ж϶����Ƿ�����
	 * @retval �����з���true��δ������false
	 */
	public boolean isFull() {
		return (rear + 1) % max == front;
	}
	
	/**
	 * @brief  ���
	 * @param  val: ���Ԫ��
	 * @retval ��ӳɹ�����true��ʧ�ܷ���false
	 */
	public boolean enqueue(int val) {
	    if(isFull()) {
	    	System.err.println("Error: queue is full.");
	        return false;
	    }
	    data[rear] = val;
	    rear = (rear + 1) % max;
	    return true;
	}

	/**
	 * @brief  ����
	 * @note   ���������ն����쳣
	 * @retval ����Ԫ��
	 */
	public int dequeue() {
	    int ret = data[front];
	    front = (front + 1) % max;
	    return ret;
	}
	
    public static void main(String[] args) {
    	CircularQueue queue = new CircularQueue(5);
    	
    	queue.enqueue(1);			// ͷ [1] β
    	queue.enqueue(2);			// ͷ [1, 2] β
    	queue.enqueue(3);			// ͷ [1, 2, 3] β
    	queue.enqueue(4);			// ͷ [1, 2, 3, 4] β
    	queue.enqueue(5);			// ͷ [1, 2, 3, 4, 5] β
    	
        while(!queue.isEmpty()) {
            System.out.println(queue.dequeue());
        }
    }
}