import java.util.Arrays;

public class QuickSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
	    quickSort(arr, 0, arr.length-1);
	    System.out.println(Arrays.toString(arr));
	}

	public static void binaryInsertionSort(int[] arr, int left, int right) {
		for (int i = left + 1; i <= right; i++) {
			int temp = arr[i];
			int start = left;
			int end = i - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (arr[mid] > temp) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			}
			int j;
			for (j = i - 1; j > end; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}

	/**
	 * 选择基准值（随机）
	 */
	public static int selectRandomPivot(int[] arr, int start, int end) {
		int pos = (int)(Math.random() * (end - start)) + start;
		int temp = arr[pos];
		arr[pos] = arr[start];
		arr[start] = temp;
		return arr[start];
	}

	/**
	 * 选择基准值（三数取中）
	 */
	public static int selectMedianPivot(int[] arr, int start, int end) {
		int mid = start + (end - start) / 2;
		if(arr[mid] > arr[end]) {
			int temp = arr[mid];
			arr[mid] = arr[end];
			arr[end] = temp;
		}
		if(arr[start] > arr[end]) {
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
		if(arr[mid] > arr[start]) {
			int temp = arr[mid];
			arr[mid] = arr[start];
			arr[start] = temp;
		}
		// 此时arr[mid] <= arr[start] <= arr[end]
		return arr[start];
	}

	/**
	 * 聚集相等基准值
	 * @param arr - 待排序数组
	 * @param start - 数组开始位置
	 * @param end - 数组结束位置
	 * @param pivotPos - 基准值下标
	 * @return - 基准值左右边界
	 */
	public static int[] gather(int[] arr, int start, int end, int pivotPos) {
		if(start >= end) {
			return null;
		}

		int[] boundary = new int[2];

		int cnt = pivotPos - 1;
		for(int i = pivotPos - 1; i >= start; i--) {
			if(arr[i] == arr[pivotPos]) {
				int temp = arr[i];
				arr[i] = arr[cnt];
				arr[cnt] = temp;
				cnt--;
			}
		}
		boundary[0] = cnt;

		cnt = pivotPos + 1;
		for(int i = pivotPos + 1; i <= end; i++) {
			if(arr[i] == arr[pivotPos]) {
				int temp = arr[i];
				arr[i] = arr[cnt];
				arr[cnt] = temp;
				cnt++;
			}
		}
		boundary[1] = cnt;

		return boundary;
	}

	public static void quickSort(int[] arr, int start, int end) {
		if(end - start >= 10) {
			binaryInsertionSort(arr, start, end);
			return;
		}

		while(start < end) {
	        int i = start;
	        int j = end;
	        int pivot = selectMedianPivot(arr, start, end);

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

	        // 聚集与基准值相等元素
			int[] boundary = gather(arr, start, end, i);
			int left = boundary[0];
			int right = boundary[1];

	        quickSort(arr, start, left);
	        // quickSort(arr, right, end);		// 消除尾递归
			start = right;
	    } 
	}
}