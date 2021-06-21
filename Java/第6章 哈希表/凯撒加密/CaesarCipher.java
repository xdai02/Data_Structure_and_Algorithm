public class CaesarCipher {
    private int key;    // 凯撒机密位移量

    public CaesarCipher() {
        this.key = 3;   // 默认位移量为3
    }

    public CaesarCipher(int key) {
        this.key = key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public int getKey(){
        return this.key;
    }

    /**
     * @brief  凯撒加密
     * @note  加密算法：ciphertext[i] = (plaintext[i] + Key) % 128
     * @param  plaintext: 明文
     * @retval 密文
     */
    public String encrypt(String plaintext) {
        int n = plaintext.length();
        char[] ciphertext = new char[n];
        for(int i = 0; i < n; i++) {
            ciphertext[i] = (char)((plaintext.charAt(i) + key) % 128);
        }
        return String.valueOf(ciphertext);
    }

    /**
     * @brief  凯撒解密
     * @note   解密算法：plaintext[i] = (ciphertext[i] - key + 128) % 128
     * @param  ciphertext: 密文
     * @retval 明文
     */
    public String decrypt(String ciphertext) {
        int n = ciphertext.length();
        char[] plaintext = new char[n];
        for(int i = 0; i < n; i++) {
            plaintext[i] = (char)((ciphertext.charAt(i) - key + 128) % 128);
        }
        return String.valueOf(plaintext);
    }

    public static void main(String[] args) {
        CaesarCipher caesar = new CaesarCipher();
        String plaintext = "Hello World!";

        String ciphertext = caesar.encrypt(plaintext);
        plaintext = caesar.decrypt(ciphertext);

        System.out.println("Encrypt: " + ciphertext);
        System.out.println("Decrypt: " + plaintext);
    }
}