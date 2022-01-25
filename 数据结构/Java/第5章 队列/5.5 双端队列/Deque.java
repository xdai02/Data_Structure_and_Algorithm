import java.util.List;
import java.util.LinkedList;

public class Deque<E> {
	private List<E> data;

	public Deque() {
		data = new LinkedList<E>();
	}

	public boolean isEmpty() {
		return data.size() == 0;
	}

	public void addFront(E val) {
		data.add(0, val);
	}

	public void addRear(E val) {
		data.add(val);
	}

	public E removeFront() {
		return data.remove(0);
	}

	public E removeRear() {
		return data.remove(data.size() - 1);
	}

	public E getFront() {
		return data.get(0);
	}

	public E getRear() {
		return data.get(data.size() - 1);
	}

	public static void main(String[] args) {
		Deque<Integer> deque = new Deque<>();
		deque.addFront(11);			// 11
		deque.addFront(22);			// 22 11
		deque.removeRear();			// 22
		deque.addRear(33);			// 22 33
		deque.addRear(44);			// 22 33 44
		deque.removeFront();		// 33 44
		System.out.println(deque.getFront());
		System.out.println(deque.getRear());
	}
}
