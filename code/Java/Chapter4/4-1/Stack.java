import java.util.ArrayList;

public class Stack<T> {
    private ArrayList<T> data;

    public Stack() {
        data = new ArrayList<T>();
    }

    public int size() {
        return data.size();
    }

    public boolean isEmpty() {
        return data.size() == 0;
    }

    public void clear() {
        data.clear();
    }

    public void push(T elem) {
        data.add(elem);
    }

    public T pop() {
        if (data.size() == 0) {
            return null;
        }
        return data.remove(data.size() - 1);
    }

    public T peek() {
        if (data.size() == 0) {
            return null;
        }
        return data.get(data.size() - 1);
    }
}
