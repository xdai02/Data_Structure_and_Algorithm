import java.util.Arrays;

public class Array {
	private int[] data;
	private int size;		// ����Ԫ�ظ���
	private int max;		// ��������
	
	/**
	 * @brief  ��ʼ������
	 */
	public Array() {
		this.size = 0;
		this.max = 5;
		this.data = new int[max];
	}
	
	/**
	 * @brief  ��ʼ������
	 * @param  n: ��������
	 */
	public Array(int n) {
		this.size = 0;
		this.max = n;
		this.data = new int[n];
	}
	
	/**
	 * @brief  ��������Ԫ�ظ���
	 * @retval ����Ԫ�ظ���
	 */
	public int getLength() {
	    return this.size;
	}
	
	/**
	 * @brief  �ж������Ƿ�����
	 * @retval �����鷵��true��δ������false
	 */
	public boolean isFull() {
	    return getLength() == max;
	}
	
	/**
	 * @brief  �ж������Ƿ�Ϊ��
	 * @retval �����鷵��true���ǿշ���false
	 */
	public boolean isEmpty() {
		return getLength() == 0;
	}
	
	/**
	 * @brief  ��ӡ����
	 */
	public void show() {
	    for(int i = 0; i < getLength(); i++) {
	        System.out.print(data[i] + " ");
	    }
	    System.out.println();
	}
	
	/**
	 * @brief  ��������
	 * @note   2������
	 */
	public void resize() {
	    // 2������
		int[] newArr = Arrays.copyOf(data, max * 2);
		max *= 2;
		data = newArr;
	}
	
	/**
	 * @brief  ׷��Ԫ��
	 * @param  val: ����Ԫ��
	 */
	public void append(int val) {
		// ������������Ҫ����
	    if(isFull()) {
	    	resize();
		}
	    data[size++] = val;
	}
	
	/**
	 * @brief  ����Ԫ��
	 * @param  index: ����λ��
	 * @param  val: ����Ԫ��
	 */
	public void insert(int index, int val) {
		// ������������Ҫ����
	    if(isFull()) {
	        resize();
		}

	    // �������鷶Χ
	    if(index < 0 || index >= max) {
	        System.err.println("Error: index out of bound.");
	    	return;
	    }

	    // ����Ԫ�ظ��� <= ����λ�� < ����
	    // ׷��Ԫ��
	    if(index >= getLength()) {
	        append(val);
	    }

	    // ��[index, size-1]��Ԫ������Ų��һλ
	    for(int i = getLength() - 1; i >= index; i--) {
	        data[i+1] = data[i];
	    }
	    // ����Ԫ��
	    data[index] = val;
	    this.size++;
	}
	
	/**
	 * @brief  ɾ��Ԫ��
	 * @param  index: ɾ��Ԫ���±�
	 */
	public void delete(int index) {
		// �������鷶Χ
	    if(index < 0 || index >= getLength()) {
	    	System.err.println("Error: index out of bound.");
	        return;
	    }

	    // ��[index+1, size-1]��Ԫ�ض���ǰŲ��һλ
	    for(int i = index + 1; i < getLength(); i++) {
	        data[i-1] = data[i];
	    }
	    this.size--;
	}
	
	/**
	 * @brief  ��ȡ����Ԫ��
	 * @note   ���������쳣
	 * @param  index: ��ȡԪ���±�
	 * @retval Ԫ������
	 */
	public int get(int index) {
		return data[index];
	}

	/**
	 * @brief  �޸�����Ԫ��
	 * @param  index: �޸�Ԫ���±�
	 * @param  val: �޸���
	 */
	public void set(int index, int val) {
	    // �������鷶Χ
	    if(index < 0 || index >= getLength()) {
	    	System.err.println("Error: index out of bound.");
	        return;
	    }
	    data[index] = val;
	}
	
	public static void main(String[] args) {
		Array arr = new Array();
		
		arr.append(1);			// [1]
		arr.append(2);			// [1, 2]
		arr.append(3);			// [1, 2, 3]
		arr.show();
		
		arr.insert(0, 4);		// [4, 1, 2, 3]
		arr.insert(1, 5);		// [4, 5, 1, 2, 3]
		arr.show();
		
		arr.delete(3);			// [4, 5, 1, 3]
		arr.delete(2);			// [4, 5, 3]
		arr.show();
		
		arr.set(0, 6);			// [6, 5, 3]
		arr.set(2, 7);			// [6, 5, 7]
		arr.show();
		
		System.out.println(arr.get(0));		// 6
	}
}
