/**
 * �ԱȲ�ͬ�㷨��data.txt��50000���������������ʱ��
 */

import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Sort {
	public static void main(String[] args) {
		final int MAX = 50000;				// ���ݸ���
		String filename = "data.txt";		// �����ļ�
		int[] arr = new int[MAX];			// �������ݵ�����
		int[] temp = new int[MAX];			// �鲢������Ҫʹ�õ���ʱ����
		long start, end;					// ��¼��ʼ������ʱ��
		double running_time = 0.0;			// ����ʱ��
		
		/*************** ��ð������ ***************/
		System.out.println("��ʼ��ð������...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    bubbleSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t��ð�����򡿣�%.3f��", running_time));
	    saveFile("bubbleSort.txt", arr);
	    
	    /*************** ��ѡ������ ***************/
		System.out.println("��ʼ��ѡ������...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    selectionSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t��ѡ�����򡿣�%.3f��", running_time));
	    saveFile("selectionSort.txt", arr);
	    
	    /*************** ���������� ***************/
		System.out.println("��ʼ����������...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    insertionSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t���������򡿣�%.3f��", running_time));
	    saveFile("insertionSort.txt", arr);
	    
	    /*************** ��ϣ������ ***************/
		System.out.println("��ʼ��ϣ������...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    shellSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t��ϣ�����򡿣�%.3f��", running_time));
	    saveFile("shellSort.txt", arr);
	    
	    /*************** ���鲢���� ***************/
		System.out.println("��ʼ���鲢����...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    mergeSort(arr, 0, MAX-1, temp);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t���鲢���򡿣�%.3f��", running_time));
	    saveFile("mergeSort.txt", arr);
	    
	    /*************** ���������� ***************/
		System.out.println("��ʼ����������...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    quickSort(arr, 0, MAX-1);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t���������򡿣�%.3f��", running_time));
	    saveFile("quickSort.txt", arr);

		/*************** �������� ***************/
		System.out.println("��ʼ��������...");
	    readData(filename, arr);
	    start = System.currentTimeMillis();
	    heapSort(arr);
	    end = System.currentTimeMillis();
	    running_time = (double)(end - start) / 1000;
	    System.out.println(String.format("\t�������򡿣�%.3f��", running_time));
	    saveFile("heapSort.txt", arr);
	}
	
	/**
	 * @brief  ���ļ���ȡ����
	 * @param  filename: �����ļ�
	 * @param  arr: �������ݵ�����
	 * @retval �ɹ�����true��ʧ�ܷ���false
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
	 * @brief  ���������浽�ļ�
	 * @param  filename: �ļ���
	 * @param  arr: ���������
	 * @retval �ɹ�����true��ʧ�ܷ���false
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
	
	/**
	 * @brief  ѡ������
	 * @param  arr: ����
	 * @param  n: ���鳤��
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
	 * @brief  ��������
	 * @param  arr: ����
	 * @param  n: ���鳤��
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
	 * @brief  ϣ������
	 * @param  arr: ����
	 * @param  n: ���鳤��
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

	    for(int m = 0; m < k; m++) {
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
	
	/**
	 * @brief  ��������
	 * @param  arr: ����������
	 * @param  start: ��ʼ�±�
	 * @param  end: �����±�
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
     * �³�����
     * @param arr �������Ķ�
     * @param parentIndex Ҫ�³��ĸ����
     * @param length �ѵ���Ч��С
     */
    public static void downAdjust(int[] arr, int parentIndex, int length) {
        // ���游����ֵ���������ĸ�ֵ
        int temp = arr[parentIndex];
        int childIndex = 2 * parentIndex + 1;

        while(childIndex < length) {
            // ������Һ��ӣ����Һ��Ӵ������ӵ�ֵ����λ���Һ���
            if(childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
                childIndex++;
            }
            // ��������С���κ�һ�����ӵ�ֵ��ֱ������
            if(temp >= arr[childIndex]) {
                break;
            }
            // ������������������ֵ����
            arr[parentIndex] = arr[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        arr[parentIndex] = temp;
    }

    /**
     * ������
     * @param arr �������Ķ�
     */
    public static void heapSort(int[] arr) {
        // ���������鹹���ɶ����
        for(int i = (arr.length-2) / 2; i >= 0; i--) {
            downAdjust(arr, i, arr.length);
        }

        // ѭ��ɾ���Ѷ�Ԫ�أ��Ƶ�����β�������ڶѲ����µĶѶ�
        for(int i = arr.length - 1; i > 0; i--) {
            // ���һ��Ԫ�غ͵�һ��Ԫ�ؽ���
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            // �³���������
            downAdjust(arr, 0, i);
        }
    }
}
