import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class ShellSort {
	public static void main(String[] args) {
		int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};

		// 希尔排序
		 shellSort(arr);

		// Hibbard增量序列
		// shellSortHibbard(arr);

		// Sedgewick增量序列
		// shellSortSedgewick(arr);

		System.out.println(Arrays.toString(arr));
	}

	/**
	 * 希尔排序（Shell增量序列）
	 * @param arr
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
	 * 生成Hibbard序列
	 * 1, 3, 7, 15, 31, 63, ...
	 * @param n - 不超过n的序列
	 * @return - Hibbard序列
	 */
	public static ArrayList getHibbardSequence(int n) {
		ArrayList<Integer> sequence = new ArrayList<>();
		int i = 1;
		while(i <= n) {
			sequence.add(i);
			i = (i << 1) + 1;
		}
		Collections.reverse(sequence);
		return sequence;
	}

	/**
	 * 希尔排序（Hibbard增量序列）
	 * @param arr
	 */
	public static void shellSortHibbard(int[] arr) {
		int n = arr.length;
		ArrayList<Integer> hibbard = getHibbardSequence(n);
		for(int gap : hibbard) {
			for(int i = gap; i < n; i++) {
				int j = i;
				int temp = arr[j];
				while(j >= gap) {
					if(temp < arr[j-gap]) {
						arr[j] = arr[j-gap];
						j -= gap;
					} else {
						break;
					}
				}
				arr[j] = temp;
			}
		}
	}

	/**
	 * 生成Sedgewick序列
	 * 1, 5, 19, 41, 109, ...
	 * @param n - 不超过n的序列
	 * @return - Sedgewick序列
	 */
	public static ArrayList getSedgewickSequence(int n) {
		ArrayList<Integer> sequence = new ArrayList<>();
		int i = 0;
		while(true) {
			// 9 * 4^i - 9 * 2^i + 1 ==> 9 * (2^(2*i) - 2^i) + 1
			int item = 9 * ((1 << (2 * i)) - (1 << i)) + 1;
			if(item <= n) {
				sequence.add(item);
			} else {
				break;
			}

			// 4^(i+2) - 3 * 2^(i+2) + 1 ==> 2^(2i+4) - 3 * 2^(i+2) + 1
			item = (1 << (2 * i + 4)) - 3 * (1 << (i + 2)) + 1;
			if(item <= n) {
				sequence.add(item);
			} else {
				break;
			}

			i++;
		}
		Collections.reverse(sequence);
		return sequence;
	}

	public static void shellSortSedgewick(int[] arr) {
		int n = arr.length;
		ArrayList<Integer> sedgewick = getSedgewickSequence(n);
		for(int gap : sedgewick) {
			for(int i = gap; i < n; i++) {
				int j = i;
				int temp = arr[j];
				while(j >= gap) {
					if(temp < arr[j-gap]) {
						arr[j] = arr[j-gap];
						j -= gap;
					} else {
						break;
					}
				}
				arr[j] = temp;
			}
		}
	}
}