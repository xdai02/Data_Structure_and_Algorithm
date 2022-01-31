import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Collections;

public class BucketSort {
    public static void main(String[] args) {
        int[] arr = {4, 6, 23, 3, 21, 8, 41, 10};
        bucketSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void bucketSort(int[] arr) {
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
        int diff = max - min;

        // 创建桶
        int bucketNum = arr.length;
        List<LinkedList<Integer>> buckets = new ArrayList<>(bucketNum);
        for(int i = 0; i < bucketNum; i++) {
            buckets.add(new LinkedList<>());
        }

        // 遍历数组，把元素放入对应桶中
        for(int i = 0; i < arr.length; i++) {
            // 计算当前元素所放置的桶号
            int num = (arr[i] - min) / (diff / (bucketNum - 1));
            buckets.get(num).add(arr[i]);
        }

        // 桶内排序
        for(int i = 0; i < bucketNum; i++) {
            Collections.sort(buckets.get(i));
        }

        // 取出元素
        int cnt = 0;
        for(LinkedList<Integer> bucket : buckets) {
            for(int data : bucket) {
                arr[cnt++] = data;
            }
        }
    }
}
