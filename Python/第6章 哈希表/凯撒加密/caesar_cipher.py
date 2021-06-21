class CaesarCipher:
    """
        凯撒加密
    """
    def __init__(self, key=3):
        """
            凯撒加密
            Args:
                key (int): 默认位移量为3
        """
        self.key = key
    
    def encrypt(self, plaintext):
        """
            凯撒加密
            加密算法：ciphertext[i] = (plaintext[i] + Key) % 128
            Args:
                plaintext (str): 明文
            Returns:
                [str]: 密文
        """
        ciphertext = ""
        for i in range(len(plaintext)):
            ciphertext += chr((ord(plaintext[i]) + self.key) % 128)
        return ciphertext
    
    def decrypt(self, ciphertext):
        """
            凯撒解密
            解密算法：plaintext[i] = (ciphertext[i] - key + 128) % 128
            Args:
                ciphertext (str): 密文
            Returns:
                [str]: 明文
        """
        plaintext = ""
        for i in range(len(ciphertext)):
            plaintext += chr((ord(ciphertext[i]) - self.key + 128) % 128)
        return plaintext

def main():
    caesar = CaesarCipher()
    plaintext = "Hello World!"

    ciphertext = caesar.encrypt(plaintext)
    plaintext = caesar.decrypt(ciphertext)

    print("Encrypt: %s" % ciphertext)
    print("Decrypt: %s" % plaintext)

if __name__ == "__main__":
    main()