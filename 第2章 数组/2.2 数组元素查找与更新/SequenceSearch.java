public class SequenceSearch {
	public static void main(String[] args) {
		int[] arr = {40, 9, 20, 93, 7, 34, 85, 91};
	    int key = 34;
	    System.out.println(key + "����λ�ã�" + sequenceSearch(arr, key));
	}
	
	/**
	 * @brief  ˳�����
	 * @param  arr: ����������
	 * @param  n: ���鳤��
	 * @param  key: �ؼ���
	 * @retval �ؼ����±꣬�����ڷ���-1
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