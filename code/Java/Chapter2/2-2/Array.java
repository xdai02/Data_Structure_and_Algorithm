import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Array<T> {
    private T[] data;
    private int size;
    private int capacity;

    public Array() {
        size = 0;
        capacity = 5;
        data = (T[]) new Object[capacity];
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        size = 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < size; i++) {
            sb.append(data[i]);
            if (i < size - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    private void resize() {
        data = Arrays.copyOf(data, capacity * 2);
        capacity *= 2;
    }

    public void add(T elem) {
        if (size == capacity) {
            resize();
        }
        data[size++] = elem;
    }

    public void add(int index, T elem) throws IndexOutOfBoundsException {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }

        if (size == capacity) {
            resize();
        }

        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }

        data[index] = elem;
        size++;
    }

    public T remove(int index) throws IndexOutOfBoundsException {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }

        T elem = data[index];
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return elem;
    }

    public T get(int index) throws IndexOutOfBoundsException {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return data[index];
    }

    public void set(int index, T elem) throws IndexOutOfBoundsException {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        data[index] = elem;
    }

    public boolean contains(T elem) {
        for (int i = 0; i < size; i++) {
            if (data[i].equals(elem)) {
                return true;
            }
        }
        return false;
    }

    public int indexOf(T elem) {
        for (int i = 0; i < size; i++) {
            if (data[i].equals(elem)) {
                return i;
            }
        }
        return -1;
    }

    public int lastIndexOf(T elem) {
        for (int i = size - 1; i >= 0; i--) {
            if (data[i].equals(elem)) {
                return i;
            }
        }
        return -1;
    }

    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index < size;
            }

            @Override
            public T next() {
                if (!hasNext()) {
                    throw new NoSuchElementException();
                }
                return data[index++];
            }
        };
    }
}