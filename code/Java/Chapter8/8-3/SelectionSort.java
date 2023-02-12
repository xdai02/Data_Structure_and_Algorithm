import java.util.Arrays;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
        selectionSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    /**
     * Selection Sort (original)
     */
    public static int[] selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        return arr;
    }

    /**
     * Selection Sort (optimized)
     */
    // public static int[] selectionSort(int[] arr) {
    //     for (int i = 0; i < arr.length / 2; i++) {
    //         int minIndex = i;
    //         int maxIndex = arr.length - i - 1;

    //         for (int j = i; j < arr.length - i; j++) {
    //             if (arr[j] < arr[minIndex]) {
    //                 minIndex = j;
    //             }
    //             if (arr[j] > arr[maxIndex]) {
    //                 maxIndex = j;
    //             }
    //         }

    //         int temp = arr[i];
    //         arr[i] = arr[minIndex];
    //         arr[minIndex] = temp;

    //         // In case of i == maxIndex before swap(arr[i], arr[minIndex]), it's now at minIndex.
    //         if (i == maxIndex) {
    //             maxIndex = minIndex;
    //         }

    //         temp = arr[arr.length - i - 1];
    //         arr[arr.length - i - 1] = arr[maxIndex];
    //         arr[maxIndex] = temp;
    //     }

    //     return arr;
    // }
}