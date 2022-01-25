/**
 * （百钱买百鸡）
 * 公鸡5文钱1只，母鸡3文钱1只，小鸡1文钱3只。
 * 如果用100文钱买100只鸡，那么公鸡、母鸡和小鸡各应该买多少只？
 */
public class HundredChicken {
	public static void main(String[] args) {
		buy(100, 100);
	}
	
	/**
	 * @brief  百钱买百鸡
	 * @note   x=公鸡，y=母鸡，z=小鸡
	 * @param  n: 鸡数
	 * @param  money: 钱
	 * @retval None
	 */
	public static void buy(int n, int money) {
        for(int x = 0; x <= n/5; x++) {
            for(int y = 0; y <= n/3; y++) {
                int z = n - x - y;
                if(z > 0 && z % 3 == 0 && 5*x + 3*y + z/3 == money) {
                    System.out.println(String.format("公鸡：%3d\t母鸡：%3d\t小鸡：%3d", x, y, z));
                }
            }
        }
    }
}