import java.util.*;

public class BinarySearchTree<T extends Comparable<T>> implements Iterable<T> {
    private class Node<T> {
        T data;
        Node<T> left;
        Node<T> right;

        Node(T elem) {
            this.data = elem;
            this.left = null;
            this.right = null;
        }
    }

    private Node<T> root;
    private int size;

    public BinarySearchTree() {
        root = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public int height() {
        return height(root);
    }

    private int height(Node<T> node) {
        if (node == null) {
            return 0;
        }
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public void clear() {
        root = null;
        size = 0;
    }

    public boolean contains(T elem) {
        Node<T> node = root;
        while (node != null) {
            if (elem.compareTo(node.data) < 0) {
                node = node.left;
            } else if (elem.compareTo(node.data) > 0) {
                node = node.right;
            } else {
                return true;
            }
        }
        return false;
    }

    public void add(T elem) {
        root = add(root, elem);
    }

    private Node<T> add(Node<T> node, T elem) {
        if (node == null) {
            size++;
            return new Node<T>(elem);
        }
        if (elem.compareTo(node.data) < 0) {
            node.left = add(node.left, elem);
        } else if (elem.compareTo(node.data) > 0) {
            node.right = add(node.right, elem);
        }
        return node;
    }

    public void remove(T elem) {
        root = remove(root, elem);
    }

    private Node<T> remove(Node<T> node, T elem) {
        if (node == null) {
            return null;
        }

        if (elem.compareTo(node.data) < 0) {
            node.left = remove(node.left, elem);
        } else if (elem.compareTo(node.data) > 0) {
            node.right = remove(node.right, elem);
        } else {
            if (node.left == null) {
                size--;
                return node.right;
            } else if (node.right == null) {
                size--;
                return node.left;
            } else {
                Node<T> successor = min(node.right);
                node.data = successor.data;
                node.right = remove(node.right, successor.data);
            }
        }
        return node;
    }

    private Node<T> min(Node<T> node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    private Node<T> max(Node<T> node) {
        while (node.right != null) {
            node = node.right;
        }
        return node;
    }

    public Iterator<T> preOrderIterator() {
        Stack<Node<T>> stack = new Stack<>();
        if (root != null) {
            stack.push(root);
        }

        return new Iterator<T>() {
            @Override
            public boolean hasNext() {
                return !stack.isEmpty();
            }

            @Override
            public T next() {
                if (!hasNext()) {
                    throw new NoSuchElementException();
                }

                Node<T> node = stack.pop();
                if (node.right != null) {
                    stack.push(node.right);
                }
                if (node.left != null) {
                    stack.push(node.left);
                }
                return node.data;
            }
        };
    }

    public Iterator<T> inOrderIterator() {
        Stack<Node<T>> stack = new Stack<>();
        Node<T> node = root;
        while (node != null) {
            stack.push(node);
            node = node.left;
        }

        return new Iterator<T>() {
            @Override
            public boolean hasNext() {
                return !stack.isEmpty();
            }

            @Override
            public T next() {
                if (!hasNext()) {
                    throw new NoSuchElementException();
                }

                Node<T> node = stack.pop();
                T data = node.data;
                node = node.right;
                while (node != null) {
                    stack.push(node);
                    node = node.left;
                }
                return data;
            }
        };
    }

    public Iterator<T> postOrderIterator() {
        Stack<Node<T>> stack = new Stack<>();
        Set<Node<T>> visited = new HashSet<>();
        stack.push(root);

        return new Iterator<T>() {
            @Override
            public boolean hasNext() {
                return !stack.isEmpty();
            }

            @Override
            public T next() {
                while (!stack.isEmpty()) {
                    Node<T> node = stack.peek();
                    if (node.left != null && !visited.contains(node.left)) {
                        stack.push(node.left);
                    } else if (node.right != null && !visited.contains(node.right)) {
                        stack.push(node.right);
                    } else {
                        stack.pop();
                        visited.add(node);
                        return node.data;
                    }
                }
                return null;
            }
        };
    }

    public Iterator<T> levelOrderIterator() {
        Queue<Node<T>> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
        }

        return new Iterator<T>() {
            @Override
            public boolean hasNext() {
                return !queue.isEmpty();
            }

            @Override
            public T next() {
                if (!hasNext()) {
                    throw new NoSuchElementException();
                }

                Node<T> node = queue.poll();
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
                return node.data;
            }
        };
    }

    @Override
    public Iterator<T> iterator() {
        return inOrderIterator();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        Iterator<T> iterator = iterator();
        while (iterator.hasNext()) {
            sb.append(iterator.next());
            if (iterator.hasNext()) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
