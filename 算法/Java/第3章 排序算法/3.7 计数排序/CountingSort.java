import java.util.Arrays;

public class CountingSort {
    public static void main(String[] args) {
        int[] arr = {3, 4, 3, 2, 1, 2, 6, 5, 4, 7};
        countingSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void countingSort(int[] arr) {
        int max = arr[0];
        int min = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
            if(arr[i] < min) {
                min = arr[i];
            }
        }

        int range = max - min + 1;
        int[] table = new int[range];

        for(int i = 0; i < arr.length; i++) {
            table[arr[i] - min]++;
        }

        int cnt = 0;
        for(int i = 0; i < range; i++) {
            while(table[i]-- > 0) {
                arr[cnt++] = i + min;
            }
        }
    }
}