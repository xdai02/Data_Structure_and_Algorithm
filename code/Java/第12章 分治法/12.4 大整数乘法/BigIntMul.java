import java.util.Collections;

public class BigIntMul {
    public static void main(String[] args) {
        String num1 = "93281";
        String num2 = "2034";
        System.out.println(bigIntMul(num1, num2));
    }
    
    /**
	 * @brief   大整数乘法
	 * @param   num1: 大整数1
	 * @param   num2: 大整数2
	 * @retval  相乘结果
	 */
    public static String bigIntMul(String num1, String num2) {
    	// 有一个为空，结果为0
    	if(num1.length() == 0 || num2.length() == 0) {
    		return "0";
    	}
    	// 终止条件
    	else if(num1.length() == 1 && num2.length() == 1) {
    		return (Integer.valueOf(num1) * Integer.valueOf(num2)) + "";
    	}
    	
    	int mid1 = num1.length() / 2;
    	int mid2 = num2.length() / 2;
    	
    	// 将num1分成两部分
    	String a = num1.substring(0, mid1);
    	String b = num1.substring(mid1);
    	// 将num2分成两部分
    	String c = num2.substring(0, mid2);
    	String d = num2.substring(mid2);
    	
    	int m = b.length();		// m次幂
    	int n = d.length();		// n次幂
    	
    	// 分治计算，分别补上幂次
    	String x1 = bigIntMul(a, c) + String.join("", Collections.nCopies(m+n, "0"));
    	String x2 = bigIntMul(b, c) + String.join("", Collections.nCopies(n, "0"));
    	String x3 = bigIntMul(a, d) + String.join("", Collections.nCopies(m, "0"));
    	String x4 = bigIntMul(b, d);
    	
    	// 将计算结果根据最长的补零，方便之后直接相加
    	int maxLen = Math.max(Math.max(x1.length(), x2.length()), Math.max(x3.length(), x4.length()));
    	x1 = String.join("", Collections.nCopies(maxLen - x1.length(), "0")) + x1;
    	x2 = String.join("", Collections.nCopies(maxLen - x2.length(), "0")) + x2;
    	x3 = String.join("", Collections.nCopies(maxLen - x3.length(), "0")) + x3;
    	x4 = String.join("", Collections.nCopies(maxLen - x4.length(), "0")) + x4;
    	
    	// 计算x1 + x2 + x3 + x4的值，也就是原问题的解
    	String result = "";
    	int carry = 0;		// 保存进位
    	for(int i = maxLen - 1; i >= 0; i--) {
    		int s = (x1.charAt(i) - '0') + (x2.charAt(i) - '0') + (x3.charAt(i) - '0') + (x4.charAt(i) - '0') + carry;
    		result = (s % 10) + result;
    		carry = s / 10;
    	}
    	// 判断是否存在进位
    	if(carry > 0) {
    		result = carry + result;
    	}
    	
    	// 去除结果前面多余的0
    	int i = 0;
    	while(i < result.length() && result.charAt(i) == '0') {
    		i++;
    	}
    	return result.substring(i);
    }
}