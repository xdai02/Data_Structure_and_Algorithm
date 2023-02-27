public class JumpGame {
    public static void main(String[] args) {
        int[] stone = {2, 3, 1, 1, 4};
        System.out.println(canJump(stone));
    }

    public static boolean canJump(int[] stone) {
        int n = stone.length;
        boolean[] f = new boolean[n];
        f[0] = true;

        for(int j = 1; j < n; j++) {
            f[j] = false;
            for(int i = 0; i < j; i++) {
                if(f[i] && i + stone[i] >= j) {
                    f[j] = true;
                    break;
                }
            }
        }
        return f[n-1];
    }
}
