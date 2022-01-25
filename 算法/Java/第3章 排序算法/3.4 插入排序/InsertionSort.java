import java.util.Arrays;

public class InsertionSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		System.out.print("排序前：");
	    System.out.println(Arrays.toString(arr));
		
		// 未优化
	    insertionSort(arr);
		// 优化
		binaryInsertionSort(arr);
		
	    System.out.print("排序后：");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  插入排序
	 * @param  arr: 数组
	 * @param  n: 数组长度
	 */
	public static void insertionSort(int[] arr) {
	    for(int i = 1; i < arr.length; i++) {
	        int temp = arr[i];
	        int j = i - 1;
	        while(j >= 0 && temp < arr[j]) {
	            arr[j+1] = arr[j];
	            j--;
	        }
	        arr[j+1] = temp;
	    }
	}
	
	public static void binaryInsertionSort(int[] arr) {
        for(int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int start = 0;
            int end = i - 1;
            while(start <= end) {
                int mid = start + (end - start) / 2;
                if(arr[mid] > temp) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            int j;
            for(j = i - 1; j > end; j--) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}