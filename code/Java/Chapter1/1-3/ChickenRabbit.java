public class ChickenRabbit {
	public static void main(String[] args) {
		count(35, 94);
	}
	
	public static void count(int head, int foot) {
	    for(int chicken = 0; chicken <= head; chicken++) {
	        int rabbit = head - chicken;
	        if(chicken*2 + rabbit*4 == foot) {
				System.out.println("Chicken: " + chicken + ", Rabbit: " + rabbit);
	        }
	    }
	}
}