/**
 * ������ͬ����
 * ������ʮ��ͷ�����о�ʮ���㣬�ʼ��ø����Σ�
 */
public class ChickenRabbit {
	public static void main(String[] args) {
		count(35, 94);
	}
	
	/**
	 * @brief  ����ͬ��
	 * @param  head: ͷ��
	 * @param  foot: ����
	 * @retval None
	 */
	public static void count(int head, int foot) {
	    for(int chicken = 0; chicken <= head; chicken++) {
	        int rabbit = head - chicken;
	        if(chicken*2 + rabbit*4 == foot) {
	            System.out.println(String.format("����%2d\t�ã�%2d", chicken, rabbit));
	        }
	    }
	}
}