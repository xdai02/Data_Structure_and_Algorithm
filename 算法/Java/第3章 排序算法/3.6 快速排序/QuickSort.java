import java.util.Arrays;

public class QuickSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		System.out.print("排序前：");
	    System.out.println(Arrays.toString(arr));
	    quickSort(arr, 0, arr.length-1);
	    System.out.print("排序后：");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  快速排序
	 * @param  arr: 待排序数组
	 * @param  start: 开始下标
	 * @param  end: 结束下标
	 * @retval None
	 */
	public static void quickSort(int[] arr, int start, int end) {
	    if(start < end) {
	        int i = start;
	        int j = end;
	        int pivot = arr[start];

	        while(i < j) {
	            while(i < j && arr[j] > pivot) {
	                j--;
	            }
	            if(i < j) {
	                arr[i] = arr[j];
	                i++;
	            }
	            while(i < j && arr[i] < pivot) {
	                i++;
	            }
	            if(i < j) {
	                arr[j] = arr[i];
	                j--;
	            }
	        }
	        arr[i] = pivot;
	        quickSort(arr, start, i-1);
	        quickSort(arr, i+1, end);
	    } 
	}
}