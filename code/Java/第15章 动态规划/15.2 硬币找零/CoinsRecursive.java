public class CoinsRecursive {
    public static final int[] coins = {2, 5, 7};
    
    public static void main(String[] args) {
        int price = 27;
        System.out.println(getMinCoins(price));
    }

    public static int getMinCoins(int price) {
        // 0ԪǮֻ��Ҫ0öӲ��
        if(price == 0) {
            return 0;
        }
        // ��ʼ��Ϊ�����
        int coinNum = Integer.MAX_VALUE - 1;
        // ���һöӲ����2Ԫ
        if(price >= 2) {
            coinNum = Math.min(getMinCoins(price-2) + 1, coinNum);
        }
        // ���һöӲ����5Ԫ
        if(price >= 5) {
            coinNum = Math.min(getMinCoins(price-5) + 1, coinNum);
        }
        // ���һöӲ����7Ԫ
        if(price >= 7) {
            coinNum = Math.min(getMinCoins(price-7) + 1, coinNum);
        }
        return coinNum;
    }
}
