public class CaesarCipher {
    private int key;    // ��������λ����

    public CaesarCipher() {
        this.key = 3;   // Ĭ��λ����Ϊ3
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
     * @brief  ��������
     * @note  �����㷨��ciphertext[i] = (plaintext[i] + Key) % 128
     * @param  plaintext: ����
     * @retval ����
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
     * @brief  ��������
     * @note   �����㷨��plaintext[i] = (ciphertext[i] - key + 128) % 128
     * @param  ciphertext: ����
     * @retval ����
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