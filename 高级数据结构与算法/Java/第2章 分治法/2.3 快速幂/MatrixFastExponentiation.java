public class MatrixFastExponentiation {
    public static final int N = 2;

    public static void main(String[] args) {
        for(int i = 1; i <= 10; i++) {
            System.out.print(matrixFastExp(i-2) + " ");
        }
        System.out.println();
    }

    public static int[][] matrixMultiply(int[][] a, int[][] b) {
        int[][] c = new int[N][N];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    public static int matrixFastExp(int n) {
        int[][] result = {
            {1, 1},
            {1, 0}
        };
        int[][] M = {
            {1, 1},
            {1, 0}
        };

        while(n > 0) {
            if((n & 1) != 0) {
                result = matrixMultiply(result, M);
            }
            M = matrixMultiply(M, M);
            n >>= 1;
        }

        return result[0][0];
    }
}
