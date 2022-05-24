import java.util.Arrays;

public class BubbleSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		System.out.print("����ǰ��");
	    System.out.println(Arrays.toString(arr));
	    
		// δ�Ż�
		bubbleSort(arr);
		// ��һ���Ż�
		// bubbleSortOptimize1(arr);
		// �ڶ����Ż�
		// bubbleSortOptimize2(arr);

	    System.out.print("��������");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  ð������
	 * @param  arr: ����
	 * @param  n: ���鳤��
	 * @retval None
	 */
	public static void bubbleSort(int[] arr) {
	    for(int i = 0; i < arr.length; i++) {
	        for(int j = 0; j < arr.length-i-1; j++) {
	            if(arr[j] > arr[j+1]) {
	            	int temp = arr[j];
	                arr[j] = arr[j+1];
	                arr[j+1] = temp;
	            }
	        }
	    }
	}

	public static void bubbleSortOptimize1(int[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            boolean hasSwapped = false;   // �����Ƿ���������
            for(int j = 0; j < arr.length - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    arr[j] ^= arr[j+1];
                    arr[j+1] ^= arr[j];
                    arr[j] ^= arr[j+1];
                    hasSwapped = true;    // ��������
                }
            }
            // ����δ�����������Ѿ�����
            if(!hasSwapped) {
                return;
            }
        }
    }

    public static void bubbleSortOptimize2(int[] arr) {
        int len = arr.length - 1;   // �ڲ�ѭ��ִ�д���
        for(int i = 0; i < arr.length - 1; i++) {
            boolean hasSwapped = false;   // �����Ƿ���������
            int last = 0;           // ��������һ�η���������λ��
            for(int j = 0; j < len; j++) {
                if(arr[j] > arr[j+1]) {
                    arr[j] ^= arr[j+1];
                    arr[j+1] ^= arr[j];
                    arr[j] ^= arr[j+1];
                    hasSwapped = true;    // ��������
                    last = j;
                }
            }
            // ����δ�����������Ѿ�����
            if(!hasSwapped) {
                return;
            }
            len = last;             // ����һ�η���������λ��
        }
    }
}