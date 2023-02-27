import java.util.Arrays;

public class HeapSort {
    public static void main(String[] args) {
        int[] arr = {5, 8, 6, 3, 9, 2, 7, 4, 10};
        heapSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    /**
     * Heap Sort (original v1.0)
     */
    public static int[] heapSort(int[] arr) {
        for (int i = arr.length / 2 - 1; i >= 0; i--) {
            heapify(arr, i, arr.length);
        }

        for (int i = arr.length - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, 0, i);
        }

        return arr;
    }

    private static void heapify(int[] arr, int index, int n) {
        int childIndex = 2 * index + 1;
        while (childIndex < n) {
            if (childIndex + 1 < n && arr[childIndex + 1] > arr[childIndex]) {
                childIndex++;
            }
            if (arr[index] >= arr[childIndex]) {
                break;
            }
            int temp = arr[index];
            arr[index] = arr[childIndex];
            arr[childIndex] = temp;
            index = childIndex;
            childIndex = 2 * index + 1;
        }
    }
}
