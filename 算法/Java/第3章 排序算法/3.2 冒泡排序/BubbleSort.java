import java.util.Arrays;

public class BubbleSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
		System.out.print("排序前：");
	    System.out.println(Arrays.toString(arr));
	    
		// 未优化
		bubbleSort(arr);
		// 第一次优化
		// bubbleSortOptimize1(arr);
		// 第二次优化
		// bubbleSortOptimize2(arr);

	    System.out.print("排序后：");
	    System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * @brief  冒泡排序
	 * @param  arr: 数组
	 * @param  n: 数组长度
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
            boolean isSorted = false;   // 标记是否发生交换
            for(int j = 0; j < arr.length - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    arr[j] ^= arr[j+1];
                    arr[j+1] ^= arr[j];
                    arr[j] ^= arr[j+1];
                    isSorted = true;    // 发生交换
                }
            }
            // 该轮未发生交换，已经有序
            if(!isSorted) {
                return;
            }
        }
    }

    public static void bubbleSortOptimize2(int[] arr) {
        int len = arr.length - 1;   // 内层循环执行次数
        for(int i = 0; i < arr.length - 1; i++) {
            boolean isSorted = false;   // 标记是否发生交换
            int last = 0;           // 标记最后一次发生交换的位置
            for(int j = 0; j < len; j++) {
                if(arr[j] > arr[j+1]) {
                    arr[j] ^= arr[j+1];
                    arr[j+1] ^= arr[j];
                    arr[j] ^= arr[j+1];
                    isSorted = true;    // 发生交换
                    last = j;
                }
            }
            // 该轮未发生交换，已经有序
            if(!isSorted) {
                return;
            }
            len = last;             // 最后一次发生交换的位置
        }
    }
}