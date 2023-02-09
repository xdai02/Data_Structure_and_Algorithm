import java.util.LinkedList;

public class Queue<T> {
    private LinkedList<T> data;

    public Queue() {
        data = new LinkedList<T>();
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public int size() {
        return data.size();
    }

    public void enqueue(T item) {
        data.addLast(item);
    }

    public T dequeue() {
        return data.removeFirst();
    }
}