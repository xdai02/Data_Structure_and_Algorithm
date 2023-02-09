import java.util.Stack;

public class Postfix {
    public static void main(String[] args) {
        String[] expressions = {
                "1 2 +",            // 1 + 2 = 3
                "2 3 4 + *",        // 2 * (3 + 4) = 14
                "1 2 + 3 4 + *",    // (1 + 2) * (3 + 4) = 21
                "3 4 2 + * 5 *",    // 3 * (4 + 2) * 5 = 90
                "50 20 - 2 /",      // (50 - 20) / 2 = 15
        };

        for (String expression : expressions) {
            System.out.println(expression + " = " + calculate(expression));
        }
    }

    public static double calculate(String expression) {
        Stack<Double> stack = new Stack<Double>();
        String[] tokens = expression.split(" ");

        for (String token : tokens) {
            if (token.equals("+")) {
                double right = stack.pop();
                double left = stack.pop();
                stack.push(left + right);
            } else if (token.equals("-")) {
                double right = stack.pop();
                double left = stack.pop();
                stack.push(left - right);
            } else if (token.equals("*")) {
                double right = stack.pop();
                double left = stack.pop();
                stack.push(left * right);
            } else if (token.equals("/")) {
                double right = stack.pop();
                double left = stack.pop();
                stack.push(left / right);
            } else {
                stack.push(Double.parseDouble(token));
            }
        }

        return stack.pop();
    }
}