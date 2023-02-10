public class BigIntAdd {
    public static void main(String[] args) {
        System.out.println(bigIntAdd("426709752318", "95481253129"));
    }

    public static String bigIntAdd(String num1, String num2) {
        if (num1.length() > num2.length()) {
            num2 = String.format("%0" + (num1.length() - num2.length()) + "d%s", 0, num2);
        } else {
            num1 = String.format("%0" + (num2.length() - num1.length()) + "d%s", 0, num1);
        }

        String result = "";
        int carry = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            int digit_sum = (Character.getNumericValue(num1.charAt(i)) + Character.getNumericValue(num2.charAt(i)) + carry);
            carry = digit_sum / 10;
            int digit = digit_sum % 10;
            result = digit + result;
        }

        if (carry > 0) {
            result = carry + result;
        }
        return result;
    }
}
