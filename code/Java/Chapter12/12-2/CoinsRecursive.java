public class CoinsRecursive {
    public static final int[] coins = {2, 5, 7};
    
    public static void main(String[] args) {
        int price = 27;
        System.out.println(getMinCoins(price));
    }

    public static int getMinCoins(int price) {
        // 0元钱只需要0枚硬币
        if(price == 0) {
            return 0;
        }
        // 初始化为无穷大
        int coinNum = Integer.MAX_VALUE - 1;
        // 最后一枚硬币是2元
        if(price >= 2) {
            coinNum = Math.min(getMinCoins(price-2) + 1, coinNum);
        }
        // 最后一枚硬币是5元
        if(price >= 5) {
            coinNum = Math.min(getMinCoins(price-5) + 1, coinNum);
        }
        // 最后一枚硬币是7元
        if(price >= 7) {
            coinNum = Math.min(getMinCoins(price-7) + 1, coinNum);
        }
        return coinNum;
    }
}
