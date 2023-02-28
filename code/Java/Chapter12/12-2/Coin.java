import java.util.Arrays;

public class Coin {
    public static void main(String[] args) {
        int[] coins = {2, 5, 7};
        int price = 27;
        System.out.println(getMinCoinsRecursive(coins, price));
        System.out.println(getMinCoinsDp(coins, price));
    }

    public static int getMinCoinsRecursive(int[] coins, int price) {
        if (price <= 0) {
            return 0;
        }

        int minCoins = Integer.MAX_VALUE - 1;
        for (int coin : coins) {
            if (price >= coin) {
                minCoins = Math.min(getMinCoinsRecursive(coins, price - coin) + 1, minCoins);
            }
        }

        return minCoins;
    }

    public static int getMinCoinsDp(int[] coins, int price) {
        int[] dp = new int[price + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i <= price; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i - coin] + 1, dp[i]);
                }
            }
        }

        return dp[price];
    }
}
