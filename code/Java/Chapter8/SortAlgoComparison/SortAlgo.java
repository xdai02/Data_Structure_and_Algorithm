import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Random;
import java.util.Stack;

public class SortAlgo {
    private static volatile SortAlgo sortAlgo;
    private static Class clazz;

    private static final int INSERTION_SORT_THRESHOLD = 10;

    private SortAlgo(Class clazz) {
        this.clazz = clazz;
    }

    /**
     * Singleton Pattern
     *
     * @param clazz Class of data
     * @return Singleton instance of SortAlgo
     */
    public static SortAlgo getInstance(Class clazz) {
        if (sortAlgo == null) {
            synchronized (SortAlgo.class) {
                if (sortAlgo == null) {
                    sortAlgo = new SortAlgo(clazz);
                }
            }
        }
        return sortAlgo;
    }

    /**
     * Bubble Sort (original v1.0)
     */
    public static <T extends Number & Comparable<T>> T[] bubbleSortV10(T[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        return arr;
    }


    /**
     * Bubble Sort (optimized v2.0)
     */
    public static <T extends Comparable<T>> T[] bubbleSortV20(T[] arr) {
        for (int i = 0; i < arr.length; i++) {
            boolean swapped = false;
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }

        return arr;
    }

    /**
     * Bubble Sort (optimized v2.1)
     */
    public static <T extends Comparable<T>> T[] bubbleSortV21(T[] arr) {
        int right = arr.length - 1;
        for (int i = 0; i < arr.length; i++) {
            boolean swapped = false;
            int last = 0;
            for (int j = 0; j < right; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                    last = j;
                }
            }
            if (!swapped) {
                break;
            }
            right = last;
        }

        return arr;
    }

    /**
     * Selection Sort (original v1.0)
     */
    public static <T extends Comparable<T>> T[] selectionSortV10(T[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j].compareTo(arr[minIndex]) < 0) {
                    minIndex = j;
                }
            }
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        return arr;
    }

    /**
     * Selection Sort (optimized v2.0)
     */
    public static <T extends Comparable<T>> T[] selectionSortV20(T[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            int minIndex = i;
            int maxIndex = arr.length - i - 1;

            for (int j = i; j < arr.length - i; j++) {
                if (arr[j].compareTo(arr[minIndex]) < 0) {
                    minIndex = j;
                }
                if (arr[j].compareTo(arr[maxIndex]) > 0) {
                    maxIndex = j;
                }
            }

            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            // In case of i == maxIndex before swap(arr[i], arr[minIndex]), it's now at minIndex.
            if (i == maxIndex) {
                maxIndex = minIndex;
            }

            temp = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = arr[maxIndex];
            arr[maxIndex] = temp;
        }

        return arr;
    }

    /**
     * Insertion Sort (original v1.0)
     */
    public static <T extends Comparable<T>> T[] insertionSortV10(T[] arr) {
        for (int i = 1; i < arr.length; i++) {
            T temp = arr[i];
            int j = i - 1;
            while (j >= 0 && temp.compareTo(arr[j]) < 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }

        return arr;
    }

    /**
     * Insertion Sort (optimized v2.0)
     */
    public static <T extends Comparable<T>> T[] insertionSortV20(T[] arr) {
        for (int i = 1; i < arr.length; i++) {
            T temp = arr[i];
            int left = 0;
            int right = i - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (temp.compareTo(arr[mid]) < 0) {
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
     * Shell Sort (original v1.0)
     */
    public static <T extends Comparable<T>> T[] shellSortV10(T[] arr) {
        int gap = arr.length / 2;

        while (gap > 0) {
            for (int i = gap; i < arr.length; i++) {
                T temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap].compareTo(temp) > 0) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
            gap /= 2;
        }

        return arr;
    }

    /**
     * Shell Sort (Hibbard)
     */
    public static <T extends Comparable<T>> T[] shellSortHibbard(T[] arr) {
        int k = (int) (Math.log(arr.length) / Math.log(2));

        while (k >= 0) {
            int gap = (int) (Math.pow(2, k) - 1);
            for (int i = gap; i < arr.length; i++) {
                T temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap].compareTo(temp) > 0) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
            k--;
        }

        return arr;
    }

    /**
     * Shell Sort (Sedgewick)
     */
    public static <T extends Comparable<T>> T[] shellSortSedgewick(T[] arr) {
        int k = (int) (Math.log(arr.length / 3) / Math.log(2));

        while (k >= 0) {
            int gap = (int) (Math.pow(4, k) + 3 * Math.pow(2, k - 1) + 1);
            for (int i = gap; i < arr.length; i++) {
                T temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap].compareTo(temp) > 0) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
            k--;
        }

        return arr;
    }

    /**
     * Merge Sort (original v1.0)
     */
    public static <T extends Comparable<T>> T[] mergeSortV10(T[] arr) {
        if (arr.length <= 1) {
            return arr;
        }

        int mid = arr.length / 2;
        T[] leftHalf = Arrays.copyOfRange(arr, 0, mid);
        T[] rightHalf = Arrays.copyOfRange(arr, mid, arr.length);

        mergeSortV10(leftHalf);
        mergeSortV10(rightHalf);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < leftHalf.length && j < rightHalf.length) {
            if (leftHalf[i].compareTo(rightHalf[j]) < 0) {
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
    public static <T extends Comparable<T>> T[] mergeSortV20(T[] arr) {
        if (arr.length <= INSERTION_SORT_THRESHOLD) {
            return insertionSortV20(arr);
        }

        int mid = arr.length / 2;
        T[] leftHalf = Arrays.copyOfRange(arr, 0, mid);
        T[] rightHalf = Arrays.copyOfRange(arr, mid, arr.length);

        mergeSortV20(leftHalf);
        mergeSortV20(rightHalf);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < leftHalf.length && j < rightHalf.length) {
            if (leftHalf[i].compareTo(rightHalf[j]) < 0) {
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
     * Merge Sort (optimized v3.0)
     */
    public static <T extends Comparable<T>> T[] mergeSortV30(T[] arr) {
        int currentSize = 1;
        while (currentSize < arr.length - 1) {
            int start = 0;
            while (start < arr.length - 1) {
                int mid = Math.min(start + currentSize - 1, arr.length - 1);
                int end = Math.min(start + 2 * currentSize - 1, arr.length - 1);
                merge(arr, start, mid, end);
                start = end + 1;
            }
            currentSize *= 2;
        }

        return arr;
    }

    /**
     * Helper function for Merge Sort
     */
    private static <T extends Comparable<T>> void merge(T[] arr, int start, int mid, int end) {
        if (end - start + 1 <= INSERTION_SORT_THRESHOLD) {
            T[] temp = (T[]) Array.newInstance(clazz, end - start + 1);
            System.arraycopy(arr, start, temp, 0, end - start + 1);
            insertionSortV20(temp);
            System.arraycopy(temp, 0, arr, start, end - start + 1);
            return;
        }

        int n1 = mid - start + 1;
        int n2 = end - mid;

        T[] leftHalf = (T[]) Array.newInstance(clazz, n1);
        T[] rightHalf = (T[]) Array.newInstance(clazz, n2);
        System.arraycopy(arr, start, leftHalf, 0, n1);
        System.arraycopy(arr, mid + 1, rightHalf, 0, n2);

        int i = 0;
        int j = 0;
        int k = start;

        while (i < n1 && j < n2) {
            if (leftHalf[i].compareTo(rightHalf[j]) < 0) {
                arr[k] = leftHalf[i];
                i++;
            } else {
                arr[k] = rightHalf[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftHalf[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightHalf[j];
            j++;
            k++;
        }
    }

    private static <T extends Comparable<T>> int partition(T[] arr, int start, int end, T pivot) {
        int i = start + 1;
        int j = end;

        while (i <= j) {
            while (i <= j && arr[i].compareTo(pivot) <= 0) {
                i++;
            }
            while (i <= j && arr[j].compareTo(pivot) >= 0) {
                j--;
            }
            if (i <= j) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        T temp = arr[start];
        arr[start] = arr[j];
        arr[j] = temp;
        return j;
    }

    private static <T extends Comparable<T>> int medianOfThree(T[] arr, int start, int end) {
        int mid = start + (end - start) / 2;

        T temp;
        if (arr[start].compareTo(arr[mid]) > 0) {
            temp = arr[start];
            arr[start] = arr[mid];
            arr[mid] = temp;
        }
        if (arr[start].compareTo(arr[end]) > 0) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        if (arr[mid].compareTo(arr[end]) > 0) {
            temp = arr[mid];
            arr[mid] = arr[end];
            arr[end] = temp;
        }

        return mid;
    }

    /**
     * Quick Sort (original v1.0)
     */
    public static <T extends Comparable<T>> T[] quickSortV10(T[] arr) {
        quickSortV10(arr, 0, arr.length - 1);
        return arr;
    }

    /**
     * Help function for Quick Sort (original v1.0)
     */
    private static <T extends Comparable<T>> void quickSortV10(T[] arr, int start, int end) {
        if (start < end) {
            T pivot = arr[start];

            int pivot_index = partition(arr, start, end, pivot);
            quickSortV10(arr, start, pivot_index - 1);
            quickSortV10(arr, pivot_index + 1, end);
        }
    }

    /**
     * Quick Sort (optimized v2.0)
     */
    public static <T extends Comparable<T>> T[] quickSortV20(T[] arr) {
        quickSortV20(arr, 0, arr.length - 1);
        return arr;
    }

    /**
     * Help function for Quick Sort (optimized v2.0)
     */
    private static <T extends Comparable<T>> void quickSortV20(T[] arr, int start, int end) {
        if (start < end) {
            Random random = new Random();
            int pivot_index = random.nextInt(end - start + 1) + start;
            T temp = arr[start];
            arr[start] = arr[pivot_index];
            arr[pivot_index] = temp;
            T pivot = arr[start];

            pivot_index = partition(arr, start, end, pivot);
            quickSortV20(arr, start, pivot_index - 1);
            quickSortV20(arr, pivot_index + 1, end);
        }
    }

    /**
     * Quick Sort (optimized v2.1)
     */
    public static <T extends Comparable<T>> T[] quickSortV21(T[] arr) {
        quickSortV21(arr, 0, arr.length - 1);
        return arr;
    }

    /**
     * Help function for Quick Sort (optimized v2.1)
     */
    private static <T extends Comparable<T>> void quickSortV21(T[] arr, int start, int end) {
        if (start < end) {
            int pivot_index = medianOfThree(arr, start, end);
            T temp = arr[start];
            arr[start] = arr[pivot_index];
            arr[pivot_index] = temp;
            T pivot = arr[start];

            pivot_index = partition(arr, start, end, pivot);
            quickSortV21(arr, start, pivot_index - 1);
            quickSortV21(arr, pivot_index + 1, end);
        }
    }

    /**
     * Quick Sort (optimized v2.2)
     */
    public static <T extends Comparable<T>> T[] quickSortV22(T[] arr) {
        quickSortV22(arr, 0, arr.length - 1);
        return arr;
    }

    /**
     * Help function for Quick Sort (optimized v2.2)
     */
    private static <T extends Comparable<T>> void quickSortV22(T[] arr, int start, int end) {
        if (end - start <= INSERTION_SORT_THRESHOLD) {
            T[] temp = (T[]) Array.newInstance(clazz, end - start + 1);
            System.arraycopy(arr, start, temp, 0, end - start + 1);
            insertionSortV20(temp);
            System.arraycopy(temp, 0, arr, start, end - start + 1);
            return;
        }

        int pivot_index = medianOfThree(arr, start, end);
        T temp = arr[start];
        arr[start] = arr[pivot_index];
        arr[pivot_index] = temp;
        T pivot = arr[start];

        pivot_index = partition(arr, start, end, pivot);
        quickSortV22(arr, start, pivot_index - 1);
        quickSortV22(arr, pivot_index + 1, end);
    }

    /**
     * Quick Sort (optimized v3.0)
     */
    public static <T extends Comparable<T>> T[] quickSortV30(T[] arr) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        stack.push(arr.length - 1);

        while (!stack.isEmpty()) {
            int end = stack.pop();
            int start = stack.pop();

            if (end - start + 1 <= INSERTION_SORT_THRESHOLD) {
                T[] temp = (T[]) Array.newInstance(clazz, end - start + 1);
                System.arraycopy(arr, start, temp, 0, end - start + 1);
                insertionSortV20(temp);
                System.arraycopy(temp, 0, arr, start, end - start + 1);
                continue;
            }

            int pivot_index = medianOfThree(arr, start, end);
            T temp = arr[start];
            arr[start] = arr[pivot_index];
            arr[pivot_index] = temp;
            T pivot = arr[start];

            pivot_index = partition(arr, start, end, pivot);
            stack.push(start);
            stack.push(pivot_index - 1);
            stack.push(pivot_index + 1);
            stack.push(end);
        }

        return arr;
    }
}