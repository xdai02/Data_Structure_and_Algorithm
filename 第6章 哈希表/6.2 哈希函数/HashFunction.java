public class HashFunction {
    public static void main(String[] args) {
        System.out.println(hash("abcde", 100));
    }

    /**
     * @brief  Hash function for calculating:
     *         for all i sum(key[n-i-1] * 32^i) mod tableSize
     * @param  key: key of string type
     * @param  tableSize: size of hash table
     * @retval hash value
     */
    public static int hash(String key, int tableSize) {
        int h = 0;          // hash value
        int n = key.length();
        for(int i = 0; i < n; i++) {
            h = (h << 5) + key.charAt(i);
        }
        return h % tableSize;
    }
}
