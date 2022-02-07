public class RK {
    public static void main(String[] args) {
        String s = "a simple example";
        String p = "ample";
        System.out.println(rk(s, p));
    }

    public static int rk(String s, String p) {
        int sLen = s.length();
        int pLen = p.length();

        int sHash = hash(s.substring(0, pLen)); // 文本串子串哈希值
        int pHash = hash(p);                    // 模式串哈希值

        for(int i = 0; i < sLen - pLen + 1; i++) {
            if(sHash == pHash) {
                if(match(s.substring(i, i + pLen), p)) {
                    return i;
                }
            }

            if(i < sLen - pLen) {
                sHash = nextHash(s, sHash, i, pLen);
            }
        }

        return -1;
    }

    public static int hash(String s) {
        int hashCode = 0;
        for(int i = 0; i < s.length(); i++) {
            hashCode += s.charAt(i) - 'a';
        }
        return hashCode;
    }

    public static int nextHash(String s, int hash, int start, int n) {
        hash -= s.charAt(start) - 'a';
        hash += s.charAt(start + n) - 'a';
        return hash;
    }

    public static boolean match(String s, String p) {
        return s.equals(p);
    }
}
