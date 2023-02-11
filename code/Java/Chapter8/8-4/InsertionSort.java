import java.util.Arrays;

public class InsertionSort {
    public static void main(String[] args) {
        int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }

	/**
     * Insertion Sort
     */
   	public static int[] insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
			int temp = arr[i];
			int j = i - 1;
			while (j >= 0 && temp < arr[j]) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}

		return arr;
   }

    /**
     * Binary Insertion Sort
     */
    // public static int[] insertionSort(int[] arr) {
    //     for (int i = 1; i < arr.length; i++) {
    //         int temp = arr[i];
    //         int left = 0;
    //         int right = i - 1;

    //         while (left <= right) {
    //             int mid = (left + right) / 2;
    //             if (temp < arr[mid]) {
    //                 right = mid - 1;
    //             } else {
    //                 left = mid + 1;
    //             }
    //         }

    //         for (int j = i - 1; j >= left; j--) {
    //             arr[j + 1] = arr[j];
    //         }
    //         arr[left] = temp;
    //     }

    //     return arr;
    // }
}