import java.util.Arrays;

public class MergeSort {
    private static final int INSERTION_SORT_THRESHOLD = 10;

    public static void main(String[] args) {
        int[] arr = {39, 27, 43, 3, 9, 82, 10};
        mergeSort(arr);
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

    /**
     * Merge Sort (original v1.0)
     */
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) {
            return arr;
        }

        int mid = arr.length / 2;
        int[] leftHalf = Arrays.copyOfRange(arr, 0, mid);
        int[] rightHalf = Arrays.copyOfRange(arr, mid, arr.length);

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < leftHalf.length && j < rightHalf.length) {
            if (leftHalf[i] < rightHalf[j]) {
                arr[k] = leftHalf[i];
                i++;
            } else {
                arr[k] = rightHalf[j];
                j++;
            }
            k++;
        }

        while (i < leftHalf.length) {
            arr[k] = leftHalf[i];
            i++;
            k++;
        }

        while (j < rightHalf.length) {
            arr[k] = rightHalf[j];
            j++;
            k++;
        }

        return arr;
    }

    /**
     * Merge Sort (optimized v2.0)
     */
    // public static int[] mergeSort(int[] arr) {
    //     if (arr.length <= INSERTION_SORT_THRESHOLD) {
    //         return insertionSort(arr);
    //     }

    //     int mid = arr.length / 2;
    //     int[] leftHalf = Arrays.copyOfRange(arr, 0, mid);
    //     int[] rightHalf = Arrays.copyOfRange(arr, mid, arr.length);

    //     mergeSort(leftHalf);
    //     mergeSort(rightHalf);

    //     int i = 0;
    //     int j = 0;
    //     int k = 0;

    //     while (i < leftHalf.length && j < rightHalf.length) {
    //         if (leftHalf[i] < rightHalf[j]) {
    //             arr[k] = leftHalf[i];
    //             i++;
    //         } else {
    //             arr[k] = rightHalf[j];
    //             j++;
    //         }
    //         k++;
    //     }

    //     while (i < leftHalf.length) {
    //         arr[k] = leftHalf[i];
    //         i++;
    //         k++;
    //     }

    //     while (j < rightHalf.length) {
    //         arr[k] = rightHalf[j];
    //         j++;
    //         k++;
    //     }

    //     return arr;
    // }
}
