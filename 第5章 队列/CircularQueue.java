public class CircularQueue {
	private int[] data;			// 数据域
	private int front;			// 队头
	private int rear;			// 队尾
	private int max;			// 队列容量
	
	/**
	 * @brief  初始化队列
	 * @note   循环队列需要保留一个空位
	 */
	public CircularQueue() {
		this.max = 10;
		this.data = new int[max];
		this.front = this.rear = 0;
	}
	
	/**
	 * @brief  初始化队列
	 * @note   循环队列需要保留一个空位
	 * @param  size: 队列容量
	 */
	public CircularQueue(int size) {
		this.max = size + 1;
		this.data = new int[max];
		this.front = this.rear = 0;
	}
	
	/**
	 * @brief  判断队列是否为空
	 * @retval 空队列返回true，非空返回false
	 */
	public boolean isEmpty() {
		return front == rear;
	}
	
	/**
	 * @brief  判断队列是否已满
	 * @retval 满队列返回true，未满返回false
	 */
	public boolean isFull() {
		return (rear + 1) % max == front;
	}
	
	/**
	 * @brief  入队
	 * @param  val: 入队元素
	 * @retval 入队成功返回true，失败返回false
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
	 * @brief  出队
	 * @note   可能引发空队列异常
	 * @retval 出队元素
	 */
	public int dequeue() {
	    int ret = data[front];
	    front = (front + 1) % max;
	    return ret;
	}
	
    public static void main(String[] args) {
    	CircularQueue queue = new CircularQueue(5);
    	
    	queue.enqueue(1);			// 头 [1] 尾
    	queue.enqueue(2);			// 头 [1, 2] 尾
    	queue.enqueue(3);			// 头 [1, 2, 3] 尾
    	queue.enqueue(4);			// 头 [1, 2, 3, 4] 尾
    	queue.enqueue(5);			// 头 [1, 2, 3, 4, 5] 尾
    	
        while(!queue.isEmpty()) {
            System.out.println(queue.dequeue());
        }
    }
}