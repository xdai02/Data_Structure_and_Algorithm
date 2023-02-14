import java.util.Arrays;
import java.util.Random;

public class QuickSort {
    private static final int INSERTION_SORT_THRESHOLD = 10;

    public static void main(String[] args) {
        int[] arr = {4, 7, 6, 5, 3, 2, 8, 1};
        quickSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    /**
     * Binary Insertion Sort
     */
    private static int[] insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int left = 0;
            int right = i - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (temp < arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            for (int j = i - 1; j >= left; j--) {
                arr[j + 1] = arr[j];
            }
            arr[left] = temp;
        }

        return arr;
    }

    private static int partition(int[] arr, int start, int end, int pivot) {
        int i = start + 1;
        int j = end;

        while (i <= j) {
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            while (i <= j && arr[j] >= pivot) {
                j--;
            }
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[start];
        arr[start] = arr[j];
        arr[j] = temp;
        return j;
    }

    private static int medianOfThree(int[] arr, int start, int end) {
        int mid = start + (end - start) / 2;

        int temp;
        if (arr[start] > arr[mid]) {
            temp = arr[start];
            arr[start] = arr[mid];
            arr[mid] = temp;
        }
        if (arr[start] > arr[end]) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        if (arr[mid] > arr[end]) {
            temp = arr[mid];
            arr[mid] = arr[end];
            arr[end] = temp;
        }

        return mid;
    }

    /**
     * Quick Sort
     */
    public static int[] quickSort(int[] arr) {
        quickSort(arr, 0, arr.length - 1);
        return arr;
    }

    /**
     * Help function for Quick Sort (original v1.0)
     */
    private static void quickSort(int[] arr, int start, int end) {
        if (start < end) {
            int pivot = arr[start];

            int pivot_index = partition(arr, start, end, pivot);
            quickSort(arr, start, pivot_index - 1);
            quickSort(arr, pivot_index + 1, end);
        }
    }

    // /**
    //  * Help function for Quick Sort (optimized v2.0)
    //  */
    // private static void quickSort(int[] arr, int start, int end) {
    //     if (start < end) {
    //         Random random = new Random();
    //         int pivot_index = random.nextInt(end - start + 1) + start;
    //         int temp = arr[start];
    //         arr[start] = arr[pivot_index];
    //         arr[pivot_index] = temp;
    //         int pivot = arr[start];

    //         pivot_index = partition(arr, start, end, pivot);
    //         quickSort(arr, start, pivot_index - 1);
    //         quickSort(arr, pivot_index + 1, end);
    //     }
    // }

    // /**
    //  * Help function for Quick Sort (optimized v2.1)
    //  */
    // private static void quickSort(int[] arr, int start, int end) {
    //     if (start < end) {
    //         int pivot_index = medianOfThree(arr, start, end);
    //         int temp = arr[start];
    //         arr[start] = arr[pivot_index];
    //         arr[pivot_index] = temp;
    //         int pivot = arr[start];

    //         pivot_index = partition(arr, start, end, pivot);
    //         quickSort(arr, start, pivot_index - 1);
    //         quickSort(arr, pivot_index + 1, end);
    //     }
    // }

    // /**
    //  * Help function for Quick Sort (optimized v2.2)
    //  */
    // private static void quickSort(int[] arr, int start, int end) {
    //     if (end - start <= INSERTION_SORT_THRESHOLD) {
    //         int[] temp = new int[end - start + 1];
    //         System.arraycopy(arr, start, temp, 0, end - start + 1);
    //         insertionSort(temp);
    //         System.arraycopy(temp, 0, arr, start, end - start + 1);
    //         return;
    //     }

    //     int pivot_index = medianOfThree(arr, start, end);
    //     int temp = arr[start];
    //     arr[start] = arr[pivot_index];
    //     arr[pivot_index] = temp;
    //     int pivot = arr[start];

    //     pivot_index = partition(arr, start, end, pivot);
    //     quickSort(arr, start, pivot_index - 1);
    //     quickSort(arr, pivot_index + 1, end);
    // }
}
