def hash(key, table_size):
    """
        Hash function for calculating:
        for all i sum(key[n-i-1] * 32^i) mod tableSize
        
        Args:
            key (str): key of string type
            table_size (int): size of hash table

        Returns:
            [int]: hash value
    """
    h = 0       # hash value
    for i in range(len(key)):
        h = (h << 5) + ord(key[i])
    return h % table_size

def main():
    print(hash("abcde", 100))

if __name__ == "__main__":
    main()