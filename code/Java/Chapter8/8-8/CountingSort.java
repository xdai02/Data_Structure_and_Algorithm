import java.util.Arrays;
import java.util.Collections;

public class CountingSort {
    public static void main(String[] args) {
        int[] arr = {95, 94, 91, 98, 99, 90, 99, 93, 91, 92};
        countingSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static int[] countingSort(int[] arr) {
        if (arr.length == 0) {
            return arr;
        }

        int maxVal = Arrays.stream(arr).max().getAsInt();
        int minVal = Arrays.stream(arr).min().getAsInt();

        int range = maxVal - minVal + 1;
        int[] counts = new int[range];

        for (int i = 0; i < arr.length; i++) {
            counts[arr[i] - minVal]++;
        }

        int cnt = 0;
        for (int i = 0; i < range; i++) {
            while (counts[i] > 0) {
                arr[cnt++] = i + minVal;
                counts[i]--;
            }
        }

        return arr;
    }
}