public class CoinsDp {
	public static void main(String[] args) {
		int[] coins = {2, 5, 7};
		int price = 27;
		System.out.println(getMinCoins(coins, price));
	}
	
	public static int getMinCoins(int[] coins, int price) {
		int[] f = new int[price+1];
		
		f[0] = 0;
		for(int i = 1; i <= price; i++) {
			f[i] = Integer.MAX_VALUE;
			for(int j = 0; j < coins.length; j++) {
				if(i >= coins[j] && f[i - coins[j]] != Integer.MAX_VALUE) {
					f[i] = Math.min(f[i - coins[j]] + 1, f[i]);
				}
			}
		}
		
		if(f[price] == Integer.MAX_VALUE) {
			f[price] = -1;
		}
		return f[price];
	}
}
