public class BinarySearch {
	public static void main(String[] args) {
		int[] arr = {7, 9, 20, 34, 40, 85, 91, 93};
	    int key = 34;
	    System.out.println(key + "����λ�ã�" + binarySearch(arr, key));
	}

	/**
	 * @brief  ���ֲ���
	 * @param  arr: ����������
	 * @param  n: ���鳤��
	 * @param  key: �ؼ���
	 * @retval �ؼ����±꣬�����ڷ���-1
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