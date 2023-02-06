public class MontePI {
	public static void main(String[] args) {
		System.out.println("PI = " + montePI(10000000));
	}
	
	public static double montePI(int n) {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
	        double x = Math.random();		// [0, 1)
	        double y = Math.random();		// [0, 1)
	        if(Math.sqrt(x*x + y*y) <= 1) {
	            cnt++;
	        }
	    }
	    return 4.0 * cnt / n;
	}
}