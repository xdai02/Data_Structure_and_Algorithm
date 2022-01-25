import java.util.Arrays;

public class CocktailSort {
    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 5, 6, 7, 8, 1};

        // 未优化
        cocktailSort1(arr);

        // 优化
        // cocktailSort2(arr);

        System.out.println(Arrays.toString(arr));
    }

    public static void cocktailSort1(int[] arr) {
        for(int i = 0; i < arr.length / 2; i++) {
            // 从左向右
            boolean isSorted = true;    // 标记当前轮是否有序
            for(int j = i; j < arr.length - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    isSorted = false;   // 发生交换
                }
            }
            if(isSorted) {
                break;
            }

            // 从右向左
            isSorted = true;
            for(int j = arr.length - i - 1; j > i; j--) {
                if(arr[j] < arr[j-1]) {
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    isSorted = false;
                }
            }
            if(isSorted) {
                break;
            }
        }
    }

    public static void cocktailSort2(int[] arr) {
        int lastLeft = 0;       // 左侧最后一次交换位置
        int lastRight = 0;      // 右侧最后一次交换位置
        int leftBorder = 0;     // 无序区左边界
        int rightBorder = arr.length - 1;   // 无序区右边界

        for(int i = 0; i < arr.length / 2; i++) {
            // 从左向右
            boolean isSorted = true;    // 标记当前轮是否有序
            for(int j = leftBorder; j < rightBorder; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    isSorted = false;   // 发生交换
                    lastRight = j;
                }
            }
            if(isSorted) {
                break;
            }
            rightBorder = lastRight;

            // 从右向左
            isSorted = true;
            for(int j = rightBorder; j > leftBorder; j--) {
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    isSorted = false;
                    lastLeft = j;
                }
            }
            if(isSorted) {
                break;
            }
            leftBorder = lastLeft;
        }
    }
}
