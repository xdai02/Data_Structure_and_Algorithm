import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Coin {
	public static void main(String[] args) {
		Integer[] coins = {1, 5, 10, 25, 100};
		int price = 36;
		ArrayList<Integer> solution = getMinCoins(coins, price);
		System.out.println(solution);
	}

	/**
	 * @brief 最少硬币找零
	 * @param coins:   硬币面值
	 * @param price:   找零数量
	 * @retval 找零方式
	 */
	public static ArrayList<Integer> getMinCoins(Integer[] coins, int price) {
		Arrays.sort(coins, Collections.reverseOrder());
		ArrayList<Integer> solution = new ArrayList<Integer>();
		for(int coin : coins) {
			int num = price / coin;
			for(int i = 0; i < num; i++) {
				solution.add(coin);
			}
			price -= coin * num;
			if(price <= 0) {
				break;
			}
		}
		return solution;
	}
}
