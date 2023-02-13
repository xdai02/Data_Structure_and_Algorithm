import java.util.Arrays;

public class MergeSort {
    public static void main(String[] args) {
        int[] arr = {39, 27, 43, 3, 9, 82, 10};
        mergeSort(arr);
        System.out.println(Arrays.toString(arr));
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

    /**
     * Merge Sort (optimized v2.0)
     */
    // public static int[] mergeSort(int[] arr) {
    //     if (arr.length <= 10) {
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

    /**
     * Helper function for Merge Sort
     */
    // private static void merge(int[] arr, int left, int mid, int right) {
    //     int n1 = mid - left + 1;
    //     int n2 = right - mid;

    //     int[] leftHalf = new int[n1];
    //     int[] rightHalf = new int[n2];

    //     for (int i = 0; i < n1; i++) {
    //         leftHalf[i] = arr[left + i];
    //     }
    //     for (int i = 0; i < n2; i++) {
    //         rightHalf[i] = arr[mid + i + 1];
    //     }

    //     int i = 0;
    //     int j = 0;
    //     int k = left;

    //     while (i < n1 && j < n2) {
    //         if (leftHalf[i] < rightHalf[j]) {
    //             arr[k] = leftHalf[i];
    //             i++;
    //         } else {
    //             arr[k] = rightHalf[j];
    //             j++;
    //         }
    //         k++;
    //     }

    //     while (i < n1) {
    //         arr[k] = leftHalf[i];
    //         i++;
    //         k++;
    //     }

    //     while (j < n2) {
    //         arr[k] = rightHalf[j];
    //         j++;
    //         k++;
    //     }
    // }

    /**
     * Merge Sort (optimized v3.0)
     */
    // public static int[] mergeSort(int[] arr) {
    //     if (arr.length <= 10) {
    //         return insertionSort(arr);
    //     }

    //     int currentSize = 1;
    //     while (currentSize < arr.length - 1) {
    //         int left = 0;
    //         while (left < arr.length - 1) {
    //             int mid = Math.min(left + currentSize - 1, arr.length - 1);
    //             int right = Math.min(left + 2 * currentSize - 1, arr.length - 1);
    //             merge(arr, left, mid, right);
    //             left = right + 1;
    //         }
    //         currentSize *= 2;
    //     }

    //     return arr;
    // }
}
