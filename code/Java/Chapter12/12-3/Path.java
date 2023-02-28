public class Path {
    public static void main(String[] args) {
        System.out.println(path(4, 8));
    }

    public static int path(int row, int col) {
        int[][] path = new int[row][n];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0) {
                    path[i][j] = 1;
                } else {
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
        }
        return path[row - 1][col - 1];
    }
}
