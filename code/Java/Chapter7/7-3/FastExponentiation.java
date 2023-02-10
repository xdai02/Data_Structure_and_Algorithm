public class FastExponentiation {
    public static void main(String[] args) {
        System.out.println(fastExponentiation(2, 18));
    }

    public static long fastExponentiation(long x, long n) {
        if (n == 0) {
            return 1;
        }

        long half;
        if (n % 2 == 0) {
            half = fastExponentiation(x, n / 2);
            return half * half;
        } else {
            half = fastExponentiation(x, (n - 1) / 2);
            return half * half * x;
        }
    }
}