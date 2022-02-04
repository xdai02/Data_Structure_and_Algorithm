public class FibonacciRecur {
	public static void main(String[] args) {
		int n = 7;
		System.out.println("斐波那契数列第" + n + "位："+ fibonacci(n));
	}
	
	public static int fibonacci(int n) {
	    if(n == 1 || n == 2) {
	        return 1;
	    }
	    return fibonacci(n-2) + fibonacci(n-1);
	}
}