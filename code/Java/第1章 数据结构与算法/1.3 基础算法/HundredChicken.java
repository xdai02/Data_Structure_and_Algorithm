/**
 * ����Ǯ��ټ���
 * ����5��Ǯ1ֻ��ĸ��3��Ǯ1ֻ��С��1��Ǯ3ֻ��
 * �����100��Ǯ��100ֻ������ô������ĸ����С����Ӧ�������ֻ��
 */
public class HundredChicken {
	public static void main(String[] args) {
		buy(100, 100);
	}
	
	/**
	 * @brief  ��Ǯ��ټ�
	 * @note   x=������y=ĸ����z=С��
	 * @param  n: ����
	 * @param  money: Ǯ
	 * @retval None
	 */
	public static void buy(int n, int money) {
        for(int x = 0; x <= n/5; x++) {
            for(int y = 0; y <= n/3; y++) {
                int z = n - x - y;
                if(z > 0 && z % 3 == 0 && 5*x + 3*y + z/3 == money) {
                    System.out.println(String.format("������%3d\tĸ����%3d\tС����%3d", x, y, z));
                }
            }
        }
    }
}