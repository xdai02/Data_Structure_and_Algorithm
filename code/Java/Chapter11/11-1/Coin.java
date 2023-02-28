import java.util.ArrayList;
import java.util.Arrays;

public class Coin {
    public static void main(String[] args) {
        int[] coins = {1, 5, 10, 25, 100};
        int price = 36;
        int[] solution = getMinCoins(coins, price);
        System.out.println(Arrays.toString(solution));
    }

    public static int[] getMinCoins(int[] coins, int price) {
        ArrayList<Integer> result = new ArrayList<Integer>();

        for (int i = coins.length - 1; i >= 0; i--) {
            while (price >= coins[i]) {
                result.add(coins[i]);
                price -= coins[i];
            }
        }

        int[] solution = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            solution[i] = result.get(i);
        }
        return solution;
    }
}
