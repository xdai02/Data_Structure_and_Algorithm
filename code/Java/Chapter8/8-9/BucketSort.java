import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class BucketSort {
    public static void main(String[] args) {
        int[] arr = {18, 11, 28, 45, 23, 49};
        bucketSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static int[] bucketSort(int[] arr) {
        if (arr.length == 0) {
            return arr;
        }

        int maxVal = Arrays.stream(arr).max().getAsInt();
        int minVal = Arrays.stream(arr).min().getAsInt();
        int bucketSize = (maxVal - minVal) / arr.length + 1;

        ArrayList<Integer>[] buckets = new ArrayList[arr.length];
        for (int i = 0; i < arr.length; i++) {
            buckets[i] = new ArrayList<>();
        }

        for (int elem : arr) {
            int index = (elem - minVal) / bucketSize;
            buckets[index].add(elem);
        }

        int i = 0;
        for (ArrayList<Integer> bucket : buckets) {
            Collections.sort(bucket);
            for (int elem : bucket) {
                arr[i++] = elem;
            }
        }

        return arr;
    }
}
