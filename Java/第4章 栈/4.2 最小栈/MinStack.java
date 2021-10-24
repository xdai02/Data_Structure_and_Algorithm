import java.util.Deque;
import java.util.LinkedList;

public class MinStack {
    private Deque<Integer> stack;
    private Deque<Integer> minStack;

    public MinStack() {
        stack = new LinkedList<Integer>();
        minStack = new LinkedList<Integer>();
        minStack.push(Integer.MAX_VALUE);
    }

    public void push(int data) {
        stack.push(data);
        minStack.push(Math.min(minStack.peek(), data));
    }

    public void pop() {
        stack.pop();
        minStack.pop();
    }

    public int peek() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();

        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);

        System.out.println(minStack.getMin());      // -3
        minStack.pop();
        System.out.println(minStack.peek());        // 0
        System.out.println(minStack.getMin());      // -2
    }
}