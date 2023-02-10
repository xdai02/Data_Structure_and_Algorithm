import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Inversion {
	public static void main(String[] args) {
		final int MAX = 50000;		// 50000����������
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
		System.out.println("���������" + countInversions(arr));
	}
	
	/**
	 * @brief  ͳ���������������
	 * @param  arr: ����
	 * @param  n: �������
	 * @retval �������
	 */
	public static int countInversions(int[] arr) {
	    int cnt = 0;        // �������
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