import java.util.Arrays;

public class SelectionSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		System.out.print("排序前：");
	    System.out.println(Arrays.toString(arr));

		// 未优化
	    selectionSort(arr);
		// 优化
		// selectionSortOptimize(arr);
		
	    System.out.print("排序后：");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  选择排序
	 * @param  arr: 数组
	 * @param  n: 数组长度
	 */
	public static void selectionSort(int[] arr) {
	    for(int i = 0; i < arr.length-1; i++) {
	        int minIndex = i;
	        for(int j = i+1; j < arr.length; j++) {
	            if(arr[j] < arr[minIndex]) {
	                minIndex = j;
	            }
	        }
	        if(i != minIndex) {
	            int temp = arr[i];
	            arr[i] = arr[minIndex];
	            arr[minIndex] = temp;
	        }
	    }
	}

	public static void selectionSortOptimize(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        while(left < right) {
            int min = left;
            int max = right;
            for(int i = left; i <= right; i++) {
                if(arr[i] < arr[min]) {
                    min = i;
                }
                if(arr[i] > arr[max]) {
                    max = i;
                }
            }
            int temp = arr[max];
            arr[max] = arr[right];
            arr[right] = temp;

            // 考虑特殊情况，最小值在最右位置
            if(min == right) {
                min = max;
            }

            temp = arr[min];
            arr[min] = arr[left];
            arr[left] = temp;

            left++;
            right--;
        }
    }
}