import java.util.ArrayList;
import java.util.List;

public class ActivitySelector {
	public static void main(String[] args) {
		// 活动集合
		int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
		// 活动开始时间集合
		int[] s = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
		// 活动结束时间集合
		int[] f = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
		
		System.out.println("选择活动：" + selectActivity(a, s, f));
	}
	
	public static List<Integer> selectActivity(int[] a, int[] s, int[] f) {
		List<Integer> activity = new ArrayList<Integer>();
		int n = s.length;
		activity.add(a[0]);
		int k = 0;
		for(int i = 1; i < n; i++) {
			if(s[i] >= f[k]) {
				activity.add(a[i]);
				k = i;
			}
		}
		return activity;
	}
}
