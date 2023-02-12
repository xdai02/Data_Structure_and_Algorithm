public class SortAlgo {
    /**
     * Bubble Sort (original)
     */
    public static <T extends Number & Comparable<T>> T[] bubbleSort(T[] arr) {
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
     * Bubble Sort (optimized v1.0)
     */
    public static <T extends Comparable<T>> T[] bubbleSortOptV1(T[] arr) {
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
     * Bubble Sort (optimized v2.0)
     */
    public static <T extends Comparable<T>> T[] bubbleSortOptV2(T[] arr) {
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
     * Selection Sort (original)
     */
    public static <T extends Comparable<T>> T[] selectionSort(T[] arr) {
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
     * Selection Sort (optimized)
     */
    public static <T extends Comparable<T>> T[] selectionSortOpt(T[] arr) {
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
     * Insertion Sort (original)
     */
    public static <T extends Comparable<T>> T[] insertionSort(T[] arr) {
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
     * Insertion Sort (optimized)
     */
    public static <T extends Comparable<T>> T[] insertionSortOpt(T[] arr) {
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
     * Shell Sort (original)
     */
    public static <T extends Comparable<T>> T[] shellSort(T[] arr) {
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
    public static <T extends Comparable<T>> T[] shellSortOptHibbard(T[] arr) {
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
    public static <T extends Comparable<T>> T[] shellSortOptSedgewick(T[] arr) {
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
}