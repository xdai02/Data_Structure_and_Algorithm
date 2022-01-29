#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3           // 凯撒加密位移量

/**
 * @brief  凯撒加密
 * @note  加密算法：ciphertext[i] = (plaintext[i] + Key) % 128
 * @param  plaintext: 明文
 * @retval 密文
 */
char* encrypt(char *plaintext) {
    int n = strlen(plaintext);
    char *ciphertext = (char *)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n; i++) {
        ciphertext[i] = (plaintext[i] + KEY) % 128;
    }
    ciphertext[n] = '\0';
    return ciphertext;
}

/**
 * @brief  凯撒解密
 * @note   解密算法：plaintext[i] = (ciphertext[i] - key + 128) % 128
 * @param  ciphertext: 密文
 * @retval 明文
 */
char* decrypt(char *ciphertext) {
    int n = strlen(ciphertext);
    char *plaintext = (char *)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n; i++) {
        plaintext[i] = (ciphertext[i] - KEY + 128) % 128;
    }
    plaintext[n] = '\0';
    return plaintext;
}

int main() {
    char *plaintext = "Hello World!";

    char *ciphertext = encrypt(plaintext);
    plaintext = decrypt(ciphertext);

    printf("Encrypt: %s\n", ciphertext);
    printf("Decrypt: %s\n", plaintext);

    free(plaintext);
    free(ciphertext);
    return 0;
}