/**
 * 对比不同算法对data.txt中50000个整数进行排序的时间
 */

import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Sort {
	public static void main(String[] args) {
		final int MAX = 50000;				// 数据个数
		String filename = "data.txt";		// 数据文件
		int[] arr = new int[MAX];			// 保存数据的数组
		int[] temp = new int[MAX];			// 归并排序需要使用的临时数组
		long start, end;					// 记录开始、结束时间
		double running_time = 0.0;			// 排序时间
		
		/*************** 【冒泡排序】 ***************/
		System.out.println("开始【冒泡排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    bubbleSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【冒泡排序】：%.3f秒", running_time));
	    saveFile("bubbleSort.txt", arr);
	    
	    /*************** 【选择排序】 ***************/
		System.out.println("开始【选择排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    selectionSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【选择排序】：%.3f秒", running_time));
	    saveFile("selectionSort.txt", arr);
	    
	    /*************** 【插入排序】 ***************/
		System.out.println("开始【插入排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    insertionSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【插入排序】：%.3f秒", running_time));
	    saveFile("insertionSort.txt", arr);
	    
	    /*************** 【希尔排序】 ***************/
		System.out.println("开始【希尔排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    shellSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【希尔排序】：%.3f秒", running_time));
	    saveFile("shellSort.txt", arr);
	    
	    /*************** 【归并排序】 ***************/
		System.out.println("开始【归并排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    mergeSort(arr, 0, MAX-1, temp);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【归并排序】：%.3f秒", running_time));
	    saveFile("mergeSort.txt", arr);
	    
	    /*************** 【快速排序】 ***************/
		System.out.println("开始【快速排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    quickSort(arr, 0, MAX-1);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【快速排序】：%.3f秒", running_time));
	    saveFile("quickSort.txt", arr);

		/*************** 【堆排序】 ***************/
		System.out.println("开始【堆排序】...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    heapSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t【堆排序】：%.3f秒", running_time));
	    saveFile("heapSort.txt", arr);
	}
	
	/**
	 * @brief  从文件读取数据
	 * @param  filename: 数据文件
	 * @param  arr: 保存数据的数组
	 * @retval 成功返回true，失败返回false
	 * */
	public static boolean readData(String filename, int[] arr) {
	    try {
			FileInputStream instream = new FileInputStream(filename);
			Scanner scanner = new Scanner(instream);
			int i = 0;
			while(scanner.hasNextInt()) {
				arr[i++] = scanner.nextInt();
			}
			instream.close();
			scanner.close();
		} catch(FileNotFoundException e) {
			e.printStackTrace();
			return false;
		} catch(IOException e) {
			e.printStackTrace();
			return false;
		}
	    return true;
	}
	
	/**
	 * @brief  排序结果保存到文件
	 * @param  filename: 文件名
	 * @param  arr: 排序后数组
	 * @retval 成功返回true，失败返回false
	 */
	public static boolean saveFile(String filename, int[] arr) {
		try {
			BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
			for(int i = 0; i < arr.length; i++) {
				writer.write(arr[i] + "\n");
			}
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			return false;
		}
	    return true;
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
	
	/**
	 * @brief  选择排序
	 * @param  arr: 数组
	 * @param  n: 数组长度
	 * @retval None
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
	
	/**
	 * @brief  插入排序
	 * @param  arr: 数组
	 * @param  n: 数组长度
	 * @retval None
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
	
	/**
	 * @brief  希尔排序
	 * @param  arr: 数组
	 * @param  n: 数组长度
	 * @retval None
	 */
	public static void shellSort(int[] arr) {
		int gap = arr.length;
	    while(gap > 1) {
	        gap /= 2;
	        for(int i = 0; i < gap; i++) {
	            for(int j = i+gap; j < arr.length; j += gap) {
	                int temp = arr[j];
	                int k = j - gap;
	                while(k >= 0 && arr[k] > temp) {
	                    arr[k+gap] = arr[k];
	                    k -= gap;
	                }
	                arr[k+gap] = temp;
	            }
	        }
	    }    
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

	    for(int m = 0; m < k; m++) {
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

	/**
     * 下沉调整
     * @param arr 待调整的堆
     * @param parentIndex 要下沉的父结点
     * @param length 堆的有效大小
     */
    public static void downAdjust(int[] arr, int parentIndex, int length) {
        // 保存父结点的值，用于最后的赋值
        int temp = arr[parentIndex];
        int childIndex = 2 * parentIndex + 1;

        while(childIndex < length) {
            // 如果有右孩子，且右孩子大于左孩子的值，则定位到右孩子
            if(childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
                childIndex++;
            }
            // 如果父结点小于任何一个孩子的值，直接跳出
            if(temp >= arr[childIndex]) {
                break;
            }
            // 无需真正交换，单向赋值即可
            arr[parentIndex] = arr[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        arr[parentIndex] = temp;
    }

    /**
     * 堆排序
     * @param arr 待调整的堆
     */
    public static void heapSort(int[] arr) {
        // 把无序数组构建成二叉堆
        for(int i = (arr.length-2) / 2; i >= 0; i--) {
            downAdjust(arr, i, arr.length);
        }

        // 循环删除堆顶元素，移到数组尾部，调节堆产生新的堆顶
        for(int i = arr.length - 1; i > 0; i--) {
            // 最后一个元素和第一个元素交换
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            // 下沉调整最大堆
            downAdjust(arr, 0, i);
        }
    }
}
