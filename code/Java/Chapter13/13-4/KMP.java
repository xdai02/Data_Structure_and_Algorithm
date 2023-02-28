public class KMP {
    public static void main(String[] args) {
        String s = "GTGTGAGCTGGTGTGTGCFAA";
        String p = "GTGTGCF";
        System.out.println(kmp(s, p));
    }

    public static int[] getNexts(String p) {
        int[] next = new int[p.length()];
        int j = 0;

        for (int i = 2; i < p.length(); i++) {
            while (j != 0 && p.charAt(j) != p.charAt(i - 1)) {
                j = next[j];
            }
            if (p.charAt(j) == p.charAt(i - 1)) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    public static int kmp(String s, String p) {
        int[] next = getNexts(p);
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            while (j > 0 && s.charAt(i) != p.charAt(j)) {
                j = next[j];
            }
            if (s.charAt(i) == p.charAt(j)) {
                j++;
            }
            if (j == p.length()) {
                return i - p.length() + 1;
            }
        }
        return -1;
    }
}
