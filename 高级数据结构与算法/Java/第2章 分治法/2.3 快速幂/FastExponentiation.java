public class FastExponentiation {
    public static void main(String[] args) {
        // 2^18 = 262144
        System.out.println(fastExp(2, 18));
    }

    /**
     * 快速幂计算a^n
     */
    public static int fastExp(int a, int n) {
        int result = 1;
        while(n > 0) {
            if((n & 1) != 0) {
                result *= a;
            }
            a *= a;
            n >>= 1;
        }
        return result;
    }
}
