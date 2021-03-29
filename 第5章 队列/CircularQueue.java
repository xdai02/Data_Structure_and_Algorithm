import java.util.Queue;
import java.util.LinkedList;

public class CircularQueue {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<Integer>();

        queue.add(1);       // 头 [1] 尾
        queue.add(2);       // 头 [1, 2] 尾
        queue.add(3);		// 头 [1, 2, 3] 尾
        queue.add(4);		// 头 [1, 2, 3, 4] 尾
        queue.add(5);		// 头 [1, 2, 3, 4, 5] 尾

        while(!queue.isEmpty()) {
            System.out.println(queue.poll());
        }
    }
}