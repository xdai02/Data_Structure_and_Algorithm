/**
 * （鸡兔同笼）
 * 上有三十五头，下有九十四足，问鸡兔各几何？
 */
public class ChickenRabbit {
	public static void main(String[] args) {
		count(35, 94);
	}
	
	/**
	 * @brief  鸡兔同笼
	 * @param  head: 头数
	 * @param  foot: 脚数
	 * @retval None
	 */
	public static void count(int head, int foot) {
	    for(int chicken = 0; chicken <= head; chicken++) {
	        int rabbit = head - chicken;
	        if(chicken*2 + rabbit*4 == foot) {
	            System.out.println(String.format("鸡：%2d\t兔：%2d", chicken, rabbit));
	        }
	    }
	}
}