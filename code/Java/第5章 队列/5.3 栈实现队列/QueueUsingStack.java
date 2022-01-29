import java.util.Deque;
import java.util.LinkedList;

public class QueueUsingStack {
    private Deque<Integer> inStack;
    private Deque<Integer> outStack;

    public QueueUsingStack() {
        inStack = new LinkedList<>();
        outStack = new LinkedList<>();
    }

    public boolean isEmpty() {
        return inStack.isEmpty() && outStack.isEmpty();
    }

    public void enqueue(int data) {
        inStack.push(data);
    }

    public int dequeue() {
        if(outStack.isEmpty()) {
            while(!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
        return outStack.pop();
    }

    public static void main(String[] args) {
        QueueUsingStack q = new QueueUsingStack();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        while(!q.isEmpty()) {
            System.out.println(q.dequeue());
        }
    }
}
