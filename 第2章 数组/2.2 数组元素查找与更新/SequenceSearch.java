public class SequenceSearch {
	public static void main(String[] args) {
		int[] arr = {40, 9, 20, 93, 7, 34, 85, 91};
	    int key = 34;
	    System.out.println(key + "所在位置：" + sequenceSearch(arr, key));
	}
	
	/**
	 * @brief  顺序查找
	 * @param  arr: 待查找数组
	 * @param  n: 数组长度
	 * @param  key: 关键字
	 * @retval 关键字下标，不存在返回-1
	 */
	public static int sequenceSearch(int[] arr, int key) {
		for(int i = 0; i < arr.length; i++) {
	        if(arr[i] == key) {
	            return i;
	        }
	    }
		return -1;
	}
}