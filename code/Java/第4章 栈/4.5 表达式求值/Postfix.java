import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Postfix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter expression: ");
        String exp = scanner.nextLine();
        String postfix = infixToPostfix(exp);
        System.out.println("Postfix expression: " + postfix);
        System.out.println("Result: " + calculate(postfix));
    }

    /**
     * 运算符的优先级
     * 乘除法优先级高于加减法
     * @param op: 运算符
     * @return 优先级
     */
    public static int priority(char op) {
        if(op == '*' || op == '/') {
            return 2;
        } else if(op == '+' || op == '-') {
            return 1;
        } else {
            return 0;
        }
    }

    /**
     * 中缀表达式转换后缀表达式
     * 转换后的后缀表达式操作数之前带空格
     * @param exp: 中缀表达式
     * @return 后缀表达式
     */
    public static String infixToPostfix(String exp) {
        String postfix = "";        // 保存生成的后缀表达式
        Deque<String> stack = new LinkedList<>();

        String number = "";
        for (int i = 0; i < exp.length(); i++) {
            // 如果是数字，保存每一位数字
            if (Character.isDigit(exp.charAt(i))) {
                number += exp.charAt(i);
                continue;
            }

            // 如果读取一个完整数字，直接输出
            if (number.length() > 0) {
                postfix += number + " ";
                number = "";
            }

            // 空格忽略
            if (exp.charAt(i) == ' ') {
                continue;
            }

            // 如果是运算符，并且空栈，则直接入栈
            if (stack.isEmpty()) {
                stack.push(String.valueOf(exp.charAt(i)));
            }
            // 如果遇到左括号，将其放入栈中
            else if (exp.charAt(i) == '(') {
                stack.push(String.valueOf(exp.charAt(i)));
            }
            // 如果遇到右括号，则一直出栈并输出，直到遇到左括号为止
            // 注意，左括号只出栈并不输出
            else if (exp.charAt(i) == ')') {
                while (!stack.peek().equals("(")) {
                    postfix += stack.pop() + " ";
                }
                stack.pop();
            }
            // 如果遇到任何其它的运算符，如果为栈为空，则直接入栈
            // 否则从栈中出栈元素并输出，直到遇到优先级更低的元素（或者栈为空）位置
            // 在出栈完这些元素后，再将当前遇到的运算符入栈
            // 有一点需要注意，只有在遇到右括号的情况下才将左括号出栈，其它情况都不会出栈左括号
            else {
                while (!stack.isEmpty() && priority(exp.charAt(i)) <= priority(stack.peek().charAt(0))) {
                    postfix += stack.pop() + " ";
                }
                stack.push(String.valueOf(exp.charAt(i)));
            }
        }

        if (number.length() > 0) {
            postfix += number + " ";
            number = "";
        }

        while(!stack.isEmpty()) {
            postfix += stack.pop() + " ";
        }

        return postfix.trim();
    }

    /**
     * 判断字符串是否为数值
     * @param s: 待判断字符串
     * @return 是数值返回true，否则返回false
     */
    public static boolean isNumber(String s) {
        return s.matches("[+-]?\\d+(\\.\\d+)?");
    }

    /**
     * 表达式求值
     * @param postfix: 后缀表达式
     * @return 表达式结果
     */
    public static int calculate(String postfix) {
        Deque<Integer> stack = new LinkedList<>();

        String[] tokens = postfix.split(" ");
        for(String token : tokens) {
            if(isNumber(token)) {
                stack.push(Integer.parseInt(token));
            } else {
                int num2 = stack.pop();
                int num1 = stack.pop();
                if(token.equals("+")) {
                    stack.push(num1 + num2);
                } else if(token.equals("-")) {
                    stack.push(num1 - num2);
                } else if(token.equals("*")) {
                    stack.push(num1 * num2);
                } else if(token.equals("/")) {
                    stack.push(num1 / num2);
                }
            }
        }

        return stack.pop();
    }
}
