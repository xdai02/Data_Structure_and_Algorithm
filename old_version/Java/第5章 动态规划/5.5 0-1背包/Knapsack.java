public class Knapsack {
    private static final int ITEM_NUM = 5;
    private static final int CAPACITY = 20;

    public static void main(String[] args) {
        int[] weight = {0, 2, 3, 4, 5, 9};
        int[] value = {0, 3, 4, 5, 8, 10};
        System.out.println(getMaxValue(weight, value));
    }

    public static int getMaxValue(int[] weight, int[] value) {
        int[][] b = new int[ITEM_NUM+1][CAPACITY+1];

        for(int k = 1; k <= ITEM_NUM; k++) {
            for(int c = 1; c <= CAPACITY; c++) {
                if(weight[k] > c) {
                    b[k][c] = b[k-1][c];
                } else {
                    b[k][c] = Math.max(b[k-1][c-weight[k]] + value[k], b[k-1][c]);
                }
            }
        }
        return b[ITEM_NUM][CAPACITY];
    }
}