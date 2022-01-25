import java.util.Arrays;

public class MergeSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		int[] temp = new int[arr.length];	// ��ʱ����
		System.out.print("����ǰ��");
	    System.out.println(Arrays.toString(arr));
	    mergeSort(arr, 0, arr.length-1, temp);
	    System.out.print("�����");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  �ϲ�
	 * @param  arr: ����������
	 * @param  start: ��ʼ�±�
	 * @param  mid: �м��±�
	 * @param  end: �����±�
	 * @param  temp: ��ʱ����
	 * @retval None
	 */
	public static void merge(int[] arr, int start, int mid, int end, int[] temp) {
	    int i = start;
	    int j = mid + 1;
	    int k = 0;

	    while(i <= mid && j <= end) {
	        if(arr[i] <= arr[j]) {
	            temp[k++] = arr[i++];
	        } else {
	            temp[k++] = arr[j++];
	        }
	    }

	    while(i <= mid) {
	        temp[k++] = arr[i++];
	    }
	    while(j <= end) {
	        temp[k++] = arr[j++];
	    }

	    for(int m = 0; m < k; i++) {
	        arr[start+m] = temp[m];
	    }
	}

	/**
	 * @brief  �鲢����
	 * @param  arr: ����������
	 * @param  start: ��ʼ�±�
	 * @param  end: �����±�
	 * @param  temp: ��ʱ����
	 * @retval None
	 */
	public static void mergeSort(int[] arr, int start, int end, int[] temp) {
	    if(start < end) {
	        int mid = start + (end - start) / 2;
	        mergeSort(arr, start, mid, temp);
	        mergeSort(arr, mid+1, end, temp);
	        merge(arr, start, mid, end, temp);
	    }
	}
}