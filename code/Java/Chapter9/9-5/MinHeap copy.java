import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class MinHeap<T extends Comparable<T>> {
    private ArrayList<T> data;

    public MinHeap() {
        data = new ArrayList<>();
    }

    public MinHeap(T[] elements) {
        data = new ArrayList<>(Arrays.asList(elements));
        heapify();
    }

    public int size() {
        return data.size();
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public void clear() {
        data.clear();
    }

    private void heapify() {
        for (int i = data.size() / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    private void siftUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (parentIndex >= 0 && data.get(parentIndex).compareTo(data.get(index)) > 0) {
            T temp = data.get(index);
            data.set(index, data.get(parentIndex));
            data.set(parentIndex, temp);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    private void siftDown(int index) {
        int childIndex = 2 * index + 1;
        while (childIndex < data.size()) {
            if (childIndex + 1 < data.size() && data.get(childIndex + 1).compareTo(data.get(childIndex)) < 0) {
                childIndex++;
            }
            if (data.get(index).compareTo(data.get(childIndex)) <= 0) {
                break;
            }
            T temp = data.get(index);
            data.set(index, data.get(childIndex));
            data.set(childIndex, temp);
            index = childIndex;
            childIndex = 2 * index + 1;
        }
    }

    public void push(T elem) {
        data.add(elem);
        siftUp(data.size() - 1);
    }

    public T pop() {
        if (data.isEmpty()) {
            throw new NoSuchElementException();
        }

        T elem = data.get(0);
        data.set(0, data.get(data.size() - 1));
        data.remove(data.size() - 1);
        siftDown(0);
        return elem;
    }

    public T peek() {
        if (data.isEmpty()) {
            throw new NoSuchElementException();
        }
        return data.get(0);
    }
}
