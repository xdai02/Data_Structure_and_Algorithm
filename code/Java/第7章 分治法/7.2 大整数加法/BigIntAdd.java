import java.util.Collections;

public class BigIntAdd {
    public static void main(String[] args) {
        System.out.println(bigIntAdd("426709752318", "95481253129"));
    }

    /**
	 * @brief   大整数加法
	 * @param   num1: 大整数1
	 * @param   num2: 大整数2
	 * @retval  相加结果
	 */
    public static String bigIntAdd(String num1, String num2) {
        // 其中一个数为0，直接返回另一个数
    	if(num1.equals("0")) {
            return num2;
        } else if(num2.equals("0")) {
            return num1;
        }
    	
    	// 计算两个数中较长的整数位数
    	int maxLen = Math.max(num1.length(), num2.length());
    	// 让位数较短的整数前面补0对齐
    	num1 = String.join("", Collections.nCopies(maxLen - num1.length(), "0")) + num1;
    	num2 = String.join("", Collections.nCopies(maxLen - num2.length(), "0")) + num2;
    	
    	String result = "";		// 结果
    	int carry = 0;			// 保存进位
    	// 从右往左逐位相加
    	for(int i = maxLen - 1; i >= 0; i--) {
    		int s = (num1.charAt(i) - '0') + (num2.charAt(i) - '0') + carry;
    		result = s % 10 + result;
    		carry = s / 10;
    	}
    	
    	// 判断最高位是否有进位
    	if(carry > 0) {
    		result = carry + result;
    	}
    	
    	// 去除结果前面多余的0
    	int i = 0;
    	while(result.charAt(i) == '0') {
    		i++;
    	}
        return result.substring(i);
    }
}