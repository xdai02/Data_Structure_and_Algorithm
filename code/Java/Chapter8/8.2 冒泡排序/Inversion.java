import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Inversion {
	public static void main(String[] args) {
		final int MAX = 50000;		// 50000个整数数据
		int[] arr = new int[MAX];
	
		try {
			Scanner scanner = new Scanner(new FileInputStream("data.txt"));
			for(int i = 0; i < MAX; i++) {
				arr[i] = scanner.nextInt();
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		System.out.println("逆序对数：" + countInversions(arr));
	}
	
	/**
	 * @brief  统计数组中逆序对数
	 * @param  arr: 数组
	 * @param  n: 数组带下
	 * @retval 逆序对数
	 */
	public static int countInversions(int[] arr) {
	    int cnt = 0;        // 逆序对数
	    for(int i = 0; i < arr.length-1; i++) {
	        for(int j = i+1; j < arr.length; j++) {
	            if(arr[i] > arr[j]) {
	                cnt++;
	            }
	        }
	    }
	    return cnt;
	}
}