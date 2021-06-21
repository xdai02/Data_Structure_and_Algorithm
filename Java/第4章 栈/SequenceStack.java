public class SequenceStack {
	private int[] data;
	private int top;		// 栈顶
	private int max;		// 栈容量
	
	/**
	 * @brief  初始化栈
	 */
	public SequenceStack() {
		this.top = -1;
		this.max = 10;
		this.data = new int[max];
	}
	
	/**
	 * @brief  初始化栈
	 * @param  size: 栈容量
	 */
	public SequenceStack(int size) {
		this.top = -1;
		this.max = size;
		this.data = new int[size];
	}
	
	/**
	 * @brief  判断栈是否已满
	 * @retval 满栈返回true，未满返回false
	 */
	public boolean isFull() {
	    return this.top == this.max - 1;
	}

	/**
	 * @brief  判断栈是否为空
	 * @retval 空栈返回true，非空返回false
	 */
	public boolean isEmpty() {
	    return this.top == -1;
	}
	
	/**
	 * @brief  入栈
	 * @param  val: 入栈元素
	 * @retval 入栈成功返回true，失败返回false
	 */
	public boolean push(int val) {
	    if(isFull()) {
	        return false;
	    }
	    this.data[++this.top] = val;
	    return true;
	}

	/**
	 * @brief  出栈
	 * @note   可能引发异常
	 * @retval 出栈元素
	 */
	public int pop() {
	    return this.data[this.top--];
	}

	/**
	 * @brief  查看栈顶元素
	 * @note   可能引发异常
	 * @retval 栈顶元素
	 */
	public int peek() {
	    return this.data[this.top];
	}
	
	
	public static void main(String[] args) {
		SequenceStack s = new SequenceStack(5);
		
		s.push(1);						// 底 [1] 顶
		s.push(2);						// 底 [1, 2] 顶
		s.push(3);						// 底 [1, 2, 3] 顶
		System.out.println(s.peek());	// 3
		
		while(!s.isEmpty()) {
			System.out.println(s.pop());
		}
	}
}
