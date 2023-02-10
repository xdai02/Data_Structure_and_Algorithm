import java.util.LinkedList;

public class Deque<T> {
    private LinkedList<T> data;

    public Deque() {
        data = new LinkedList<T>();
    }

    public int size() {
        return data.size();
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public void pushFront(T elem) {
        data.addFirst(elem);
    }

    public void pushBack(T elem) {
        data.addLast(elem);
    }

    public T popFront() {
        return data.removeFirst();
    }

    public T popBack() {
        return data.removeLast();
    }

    public T front() {
        return data.getFirst();
    }

    public T back() {
        return data.getLast();
    }
}