public class Reverse {
	public static void main(String[] args) {
		String str = "hello";
		str = reverse(str);
		System.out.println(str);
	}
	
	public static String reverse(String str) {
		char[] arr = str.toCharArray();
		for(int i = 0; i < arr.length/2; i++) {
			char temp = arr[i];
			arr[i] = arr[arr.length-i-1];
			arr[arr.length-i-1] = temp;
		}
		return new String(arr);
	}
}