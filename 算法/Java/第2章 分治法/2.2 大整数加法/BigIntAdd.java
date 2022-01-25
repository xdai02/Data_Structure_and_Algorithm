import java.util.Collections;

public class BigIntAdd {
    public static void main(String[] args) {
        System.out.println(bigIntAdd("426709752318", "95481253129"));
    }

    /**
	 * @brief   �������ӷ�
	 * @param   num1: ������1
	 * @param   num2: ������2
	 * @retval  ��ӽ��
	 */
    public static String bigIntAdd(String num1, String num2) {
        // ����һ����Ϊ0��ֱ�ӷ�����һ����
    	if(num1.equals("0")) {
            return num2;
        } else if(num2.equals("0")) {
            return num1;
        }
    	
    	// �����������нϳ�������λ��
    	int maxLen = Math.max(num1.length(), num2.length());
    	// ��λ���϶̵�����ǰ�油0����
    	num1 = String.join("", Collections.nCopies(maxLen - num1.length(), "0")) + num1;
    	num2 = String.join("", Collections.nCopies(maxLen - num2.length(), "0")) + num2;
    	
    	String result = "";		// ���
    	int carry = 0;			// �����λ
    	// ����������λ���
    	for(int i = maxLen - 1; i >= 0; i--) {
    		int s = (num1.charAt(i) - '0') + (num2.charAt(i) - '0') + carry;
    		result = s % 10 + result;
    		carry = s / 10;
    	}
    	
    	// �ж����λ�Ƿ��н�λ
    	if(carry > 0) {
    		result = carry + result;
    	}
    	
    	// ȥ�����ǰ������0
    	int i = 0;
    	while(result.charAt(i) == '0') {
    		i++;
    	}
        return result.substring(i);
    }
}