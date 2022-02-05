import java.util.Collections;

public class BigIntMul {
    public static void main(String[] args) {
        String num1 = "93281";
        String num2 = "2034";
        System.out.println(bigIntMul(num1, num2));
    }
    
    /**
	 * @brief   �������˷�
	 * @param   num1: ������1
	 * @param   num2: ������2
	 * @retval  ��˽��
	 */
    public static String bigIntMul(String num1, String num2) {
    	// ��һ��Ϊ�գ����Ϊ0
    	if(num1.length() == 0 || num2.length() == 0) {
    		return "0";
    	}
    	// ��ֹ����
    	else if(num1.length() == 1 && num2.length() == 1) {
    		return (Integer.valueOf(num1) * Integer.valueOf(num2)) + "";
    	}
    	
    	int mid1 = num1.length() / 2;
    	int mid2 = num2.length() / 2;
    	
    	// ��num1�ֳ�������
    	String a = num1.substring(0, mid1);
    	String b = num1.substring(mid1);
    	// ��num2�ֳ�������
    	String c = num2.substring(0, mid2);
    	String d = num2.substring(mid2);
    	
    	int m = b.length();		// m����
    	int n = d.length();		// n����
    	
    	// ���μ��㣬�ֱ����ݴ�
    	String x1 = bigIntMul(a, c) + String.join("", Collections.nCopies(m+n, "0"));
    	String x2 = bigIntMul(b, c) + String.join("", Collections.nCopies(n, "0"));
    	String x3 = bigIntMul(a, d) + String.join("", Collections.nCopies(m, "0"));
    	String x4 = bigIntMul(b, d);
    	
    	// ��������������Ĳ��㣬����֮��ֱ�����
    	int maxLen = Math.max(Math.max(x1.length(), x2.length()), Math.max(x3.length(), x4.length()));
    	x1 = String.join("", Collections.nCopies(maxLen - x1.length(), "0")) + x1;
    	x2 = String.join("", Collections.nCopies(maxLen - x2.length(), "0")) + x2;
    	x3 = String.join("", Collections.nCopies(maxLen - x3.length(), "0")) + x3;
    	x4 = String.join("", Collections.nCopies(maxLen - x4.length(), "0")) + x4;
    	
    	// ����x1 + x2 + x3 + x4��ֵ��Ҳ����ԭ����Ľ�
    	String result = "";
    	int carry = 0;		// �����λ
    	for(int i = maxLen - 1; i >= 0; i--) {
    		int s = (x1.charAt(i) - '0') + (x2.charAt(i) - '0') + (x3.charAt(i) - '0') + (x4.charAt(i) - '0') + carry;
    		result = (s % 10) + result;
    		carry = s / 10;
    	}
    	// �ж��Ƿ���ڽ�λ
    	if(carry > 0) {
    		result = carry + result;
    	}
    	
    	// ȥ�����ǰ������0
    	int i = 0;
    	while(i < result.length() && result.charAt(i) == '0') {
    		i++;
    	}
    	return result.substring(i);
    }
}