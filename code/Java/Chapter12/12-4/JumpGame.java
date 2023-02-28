public class JumpGame {
    public static void main(String[] args) {
        int[] stones = {2, 3, 1, 1, 4};
        System.out.println(canJump(stones));
    }

    public static boolean canJump(int[] stones) {
        boolean[] canJump = new boolean[stones.length];
        canJump[0] = true;

        for(int j = 1; j < stones.length; j++) {
            canJump[j] = false;
            for(int i = 0; i < j; i++) {
                if(canJump[i] && i + stones[i] >= j) {
                    canJump[j] = true;
                    break;
                }
            }
        }
        return canJump[stones.length - 1];
    }
}
