import java.util.Arrays;

public class Array {
	private int[] data;
	private int size;		// 数组元素个数
	private int max;		// 数组容量
	
	/**
	 * @brief  初始化数组
	 */
	public Array() {
		this.size = 0;
		this.max = 5;
		this.data = new int[max];
	}
	
	/**
	 * @brief  初始化数组
	 * @param  n: 数组容量
	 */
	public Array(int n) {
		this.size = 0;
		this.max = n;
		this.data = new int[n];
	}
	
	/**
	 * @brief  计算数组元素个数
	 * @retval 数组元素个数
	 */
	public int getLength() {
	    return this.size;
	}
	
	/**
	 * @brief  判断数组是否已满
	 * @retval 满数组返回true，未满返回false
	 */
	public boolean isFull() {
	    return getLength() == max;
	}
	
	/**
	 * @brief  判断数组是否为空
	 * @retval 空数组返回true，非空返回false
	 */
	public boolean isEmpty() {
		return getLength() == 0;
	}
	
	/**
	 * @brief  打印数组
	 */
	public void show() {
	    for(int i = 0; i < getLength(); i++) {
	        System.out.print(data[i] + " ");
	    }
	    System.out.println();
	}
	
	/**
	 * @brief  数组扩容
	 * @note   2倍扩容
	 */
	public void resize() {
	    // 2倍扩容
		int[] newArr = Arrays.copyOf(data, max * 2);
		max *= 2;
		data = newArr;
	}
	
	/**
	 * @brief  追加元素
	 * @param  val: 插入元素
	 */
	public void append(int val) {
		// 数组已满，需要扩容
	    if(isFull()) {
	    	resize();
		}
	    data[size++] = val;
	}
	
	/**
	 * @brief  插入元素
	 * @param  index: 插入位置
	 * @param  val: 插入元素
	 */
	public void insert(int index, int val) {
		// 数组已满，需要扩容
	    if(isFull()) {
	        resize();
		}

	    // 超出数组范围
	    if(index < 0 || index >= max) {
	        System.err.println("Error: index out of bound.");
	    	return;
	    }

	    // 数组元素个数 <= 插入位置 < 容量
	    // 追加元素
	    if(index >= getLength()) {
	        append(val);
	    }

	    // 将[index, size-1]的元素往后挪动一位
	    for(int i = getLength() - 1; i >= index; i--) {
	        data[i+1] = data[i];
	    }
	    // 插入元素
	    data[index] = val;
	    this.size++;
	}
	
	/**
	 * @brief  删除元素
	 * @param  index: 删除元素下标
	 */
	public void delete(int index) {
		// 超出数组范围
	    if(index < 0 || index >= getLength()) {
	    	System.err.println("Error: index out of bound.");
	        return;
	    }

	    // 将[index+1, size-1]的元素都向前挪动一位
	    for(int i = index + 1; i < getLength(); i++) {
	        data[i-1] = data[i];
	    }
	    this.size--;
	}
	
	/**
	 * @brief  获取数组元素
	 * @note   可能引发异常
	 * @param  index: 获取元素下标
	 * @retval 元素内容
	 */
	public int get(int index) {
		return data[index];
	}

	/**
	 * @brief  修改数组元素
	 * @param  index: 修改元素下标
	 * @param  val: 修改至
	 */
	public void set(int index, int val) {
	    // 超出数组范围
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
