import java.util.Arrays;

public class MergeSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		int[] temp = new int[arr.length];	// 临时数组
		System.out.print("排序前：");
	    System.out.println(Arrays.toString(arr));
	    mergeSort(arr, 0, arr.length-1, temp);
	    System.out.print("排序后：");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  合并
	 * @param  arr: 待排序数组
	 * @param  start: 开始下标
	 * @param  mid: 中间下标
	 * @param  end: 结束下标
	 * @param  temp: 临时数组
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
	 * @brief  归并排序
	 * @param  arr: 待排序数组
	 * @param  start: 开始下标
	 * @param  end: 结束下标
	 * @param  temp: 临时数组
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