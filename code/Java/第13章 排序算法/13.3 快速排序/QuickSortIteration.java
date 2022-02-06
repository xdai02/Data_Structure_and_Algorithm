import java.util.Arrays;
import java.util.LinkedList;

public class QuickSortIteration {
    public static void main(String[] args) {
        int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
        quickSort(arr, 0, arr.length-1);
        System.out.println(Arrays.toString(arr));
    }

    public static int partition(int[] arr, int start, int end) {
        int i = start - 1;
        int pivot = arr[end];

        for(int j = start; j < end; j++) {
            if(arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;
        return i + 1;
    }

    public static void quickSort(int[] arr, int start, int end) {
        LinkedList<Integer> s = new LinkedList<>();
        s.push(start);
        s.push(end);

        while(!s.isEmpty()) {
            int right = s.pop();
            int left = s.pop();

            int index = partition(arr, left, right);
            if(index - 1 > left) {
                s.push(left);
                s.push(index - 1);
            }
            if(index + 1 < right) {
                s.push(index + 1);
                s.push(right);
            }
        }
    }
}