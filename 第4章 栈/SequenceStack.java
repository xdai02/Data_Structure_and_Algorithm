import java.util.Stack;

public class SequenceStack {
	public static void main(String[] args) {
		Stack<Integer> s = new Stack<Integer>();
		
		s.push(1);						// �� [1] ��
		s.push(2);						// �� [1, 2] ��
		s.push(3);						// �� [1, 2, 3] ��
		System.out.println(s.peek());	// 3
		
		while(!s.isEmpty()) {
			System.out.println(s.pop());
		}
	}
}
