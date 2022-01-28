public class SequenceStack {
	private int[] data;
	private int top;		// ջ��
	private int max;		// ջ����
	
	/**
	 * @brief  ��ʼ��ջ
	 */
	public SequenceStack() {
		this.top = -1;
		this.max = 10;
		this.data = new int[max];
	}
	
	/**
	 * @brief  ��ʼ��ջ
	 * @param  size: ջ����
	 */
	public SequenceStack(int size) {
		this.top = -1;
		this.max = size;
		this.data = new int[size];
	}
	
	/**
	 * @brief  �ж�ջ�Ƿ�����
	 * @retval ��ջ����true��δ������false
	 */
	public boolean isFull() {
	    return this.top == this.max - 1;
	}

	/**
	 * @brief  �ж�ջ�Ƿ�Ϊ��
	 * @retval ��ջ����true���ǿշ���false
	 */
	public boolean isEmpty() {
	    return this.top == -1;
	}
	
	/**
	 * @brief  ��ջ
	 * @param  val: ��ջԪ��
	 * @retval ��ջ�ɹ�����true��ʧ�ܷ���false
	 */
	public boolean push(int val) {
	    if(isFull()) {
	        return false;
	    }
	    this.data[++this.top] = val;
	    return true;
	}

	/**
	 * @brief  ��ջ
	 * @note   ���������쳣
	 * @retval ��ջԪ��
	 */
	public int pop() {
	    return this.data[this.top--];
	}

	/**
	 * @brief  �鿴ջ��Ԫ��
	 * @note   ���������쳣
	 * @retval ջ��Ԫ��
	 */
	public int peek() {
	    return this.data[this.top];
	}
	
	
	public static void main(String[] args) {
		SequenceStack s = new SequenceStack(5);
		
		s.push(1);						// �� [1] ��
		s.push(2);						// �� [1, 2] ��
		s.push(3);						// �� [1, 2, 3] ��
		System.out.println(s.peek());	// 3
		
		while(!s.isEmpty()) {
			System.out.println(s.pop());
		}
	}
}
