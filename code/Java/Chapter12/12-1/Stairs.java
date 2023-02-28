public class Stairs {
    public static void main(String[] args) {
        System.out.println(climbRecursive(10));
        System.out.println(climbDp(10));
    }

    public static int climbRecursive(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        return climbRecursive(n - 1) + climbRecursive(n - 2);
    }

    public static int climbDp(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }

        int num1 = 1;
        int num2 = 2;
        int sum = 0;
        for (int i = 3; i <= n; i++) {
            sum = num1 + num2;
            num1 = num2;
            num2 = sum;
        }
        return sum;
    }
}