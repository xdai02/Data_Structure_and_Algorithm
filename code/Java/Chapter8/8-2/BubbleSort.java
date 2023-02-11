import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    /**
     * Bubble Sort (original)
     */
     public static int[] bubbleSort(int[] arr) {
         for (int i = 0; i < arr.length; i++) {
             for (int j = 0; j < arr.length - i - 1; j++) {
                 if (arr[j] > arr[j + 1]) {
                     int temp = arr[j];
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
//    public static int[] bubbleSort(int[] arr) {
//        for (int i = 0; i < arr.length; i++) {
//            boolean swapped = false;
//            for (int j = 0; j < arr.length - i - 1; j++) {
//                if (arr[j] > arr[j + 1]) {
//                    int temp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = temp;
//                    swapped = true;
//                }
//            }
//            if (!swapped) {
//                break;
//            }
//        }
//
//        return arr;
//    }

    /**
     * Bubble Sort (optimized v2.0)
     */
//    public static int[] bubbleSort(int[] arr) {
//        int right = arr.length - 1;
//        for (int i = 0; i < arr.length; i++) {
//            boolean swapped = false;
//            int last = 0;
//            for (int j = 0; j < right; j++) {
//                if (arr[j] > arr[j + 1]) {
//                    int temp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = temp;
//                    swapped = true;
//                    last = j;
//                }
//            }
//            if (!swapped) {
//                break;
//            }
//            right = last;
//        }
//
//        return arr;
//    }
}
