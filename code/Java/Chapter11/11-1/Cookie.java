import java.util.Arrays;

public class Cookie {
    public static void main(String[] args) {
        int[] children = {1, 2};
        int[] cookies = {1, 2, 3};
        System.out.println(distribute(children, cookies));
    }

    public static int distribute(int[] children, int[] cookies) {
        Arrays.sort(children);
        Arrays.sort(cookies);
        int child = 0;
        int cookie = 0;
        while (child < children.length && cookie < cookies.length) {
            if (children[child] <= cookies[cookie++]) {
                child++;
            }
        }
        return child;
    }
}
