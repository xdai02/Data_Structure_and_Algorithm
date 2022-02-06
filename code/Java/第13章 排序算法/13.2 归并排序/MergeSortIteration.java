import java.util.Arrays;

public class MergeSortIteration {
    public static void main(String[] args) {
        int[] arr = {5, 8, 6, 3, 9, 2, 1, 7};
        mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void mergeSort(int[] arr) {
        int n = arr.length;
        int[] temp = new int[n];
        int pos = 0;            // 临时数组的下表
        int left1, left2;       // 左子数组边界
        int right1, right2;     // 右子数组边界

        for (int i = 1; i < n; i *= 2) {
            for (left1 = 0; left1 < n - i; left1 = right2) {
                // 设置子数组边界
                right1 = left2 = left1 + i;
                right2 = left2 + i;

                // 防止右边界越界
                right2 = right2 > n ? n : right2;

                pos = 0;
                while (left1 < left2 && right1 < right2) {
                    if (arr[left1] < arr[right1]) {
                        temp[pos++] = arr[left1++];
                    } else {
                        temp[pos++] = arr[right1++];
                    }
                }

                while (left1 < left2) {
                    arr[--right1] = arr[--left2];
                }

                // 将排好序的部分保存回数组
                while (pos > 0) {
                    arr[--right1] = temp[--pos];
                }
            }
        }
    }
}
