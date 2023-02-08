import java.util.Stack;

public class Bracket {
    public static void main(String[] args) {
        String[] brackets = {
                "()",
                "()[]{}",
                "(]",
                "([)]",
                "{[]}",
        };

        for (String bracket : brackets) {
            System.out.println(bracket + ": " + isValidBracket(bracket));
        }
    }

    private static boolean isValidBracket(String bracket) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < bracket.length(); i++) {
            char c = bracket.charAt(i);

            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}
