public class BinarySearch {
	public static void main(String[] args) {
		int[] arr = {7, 9, 20, 34, 40, 85, 91, 93};
	    int key = 34;
	    System.out.println(key + "所在位置：" + binarySearch(arr, key));
	}

	/**
	 * @brief  二分查找
	 * @param  arr: 待查找数组
	 * @param  n: 数组长度
	 * @param  key: 关键字
	 * @retval 关键字下标，不存在返回-1
	 */
	public static int binarySearch(int[] arr, int key) {
	    int start = 0;
	    int end = arr.length - 1;
	    while(start <= end) {
	        int mid = start + (end - start) / 2;
	        if(arr[mid] == key) {
	            return mid;
	        } else if(arr[mid] < key) {
	            start = mid + 1;
	        } else {
	            end = mid - 1;
	        }
	    }
	    return -1;
	}
}