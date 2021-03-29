import java.util.ArrayList;

public class Array {
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<Integer>();
		
		arr.add(1);			// [1]
		arr.add(2);			// [1, 2]
		arr.add(3);			// [1, 2, 3]
		System.out.println(arr);
		
		arr.add(0, 4);		// [4, 1, 2, 3]
		arr.add(1, 5);		// [4, 5, 1, 2, 3]
		System.out.println(arr);
		
		arr.remove(3);		// [4, 5, 1, 3]
		arr.remove(2);		// [4, 5, 3]
		System.out.println(arr);
		
		arr.set(0, 6);		// [6, 5, 3]
		arr.set(2, 7);		// [6, 5, 7]
		System.out.println(arr);
		
		System.out.println(arr.get(0));		// 6
	}
}
