import java.util.ArrayList;

public class Stack {
    private ArrayList<Node> data;

    public Stack() {
        data = new ArrayList<>();
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public void push(Node node) {
        data.add(node);
    }

    public Node pop() {
        Node top = data.get(data.size() - 1);
        data.remove(data.size() - 1);
        return top;
    }

    public Node peek() {
        return data.get(data.size() - 1);
    }
}
