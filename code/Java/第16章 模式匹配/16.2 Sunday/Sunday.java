public class Sunday {
    public static void main(String[] args) {
        String s = "a simple example";
        String p = "ample";
        System.out.println(sunday(s, p));
    }

    public static int sunday(String S, String P) {
        char[] s = S.toCharArray();
        char[] p = P.toCharArray();
        int i = 0;
        int j = 0;
        int result = 0;

        while(i < s.length && j < p.length) {
            if(s[i] == p[j]) {
                i++;
                j++;
                continue;
            }

            int idx = result + p.length;
            if(idx > s.length) {
                return -1;
            }

            int k = p.length - 1;
            while(k >= 0 && s[idx] != p[k]) {
                k--;
            }

            i = result;
            i += p.length - k;
            result = i;
            j = 0;

            if(result + p.length > s.length) {
                return -1;
            }
        }

        return result;
    }
}
