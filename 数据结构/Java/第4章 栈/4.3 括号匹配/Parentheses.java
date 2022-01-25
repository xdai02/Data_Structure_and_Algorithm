import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class Parentheses {
    public static void main(String[] args) {
        String[] parentheses = {"()", "()[]{}", "(]", "([)]", "{[]}"};
        for(String s : parentheses) {
            System.out.println(s + ": " + validParentheses(s));
        }
    }

    public static boolean validParentheses(String s) {
        int n = s.length();
        if(n % 2 == 1) {
            return false;
        }

        Map<Character, Character> pairs = new HashMap<Character, Character>() {{
            put(')', '(');
            put(']', '[');
            put('}', '{');
        }};
        Deque<Character> stack = new LinkedList<Character>();
        for(int i = 0; i < n; i++) {
            char paren = s.charAt(i);
            if(pairs.containsKey(paren)) {
                if(stack.isEmpty() || stack.peek() != pairs.get(paren)) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(paren);
            }
        }
        return stack.isEmpty();
    }
}
