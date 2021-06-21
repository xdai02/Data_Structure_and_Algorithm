#include <stdio.h>

/**
 * @brief  Hash function for calculating:
 *         for all i sum(key[n-i-1] * 32^i) mod tableSize
 * @param  key: key of string type
 * @param  tableSize: size of hash table
 * @retval hash value
 */
int hash(char *key, int tableSize) {
    int h = 0;          // hash value
    int i = 0;
    while(key[i] != '\0') {
        h = (h << 5) + key[i];
        i++;
    }
    return h % tableSize;
}

int main() {
    printf("%d\n", hash("abcde", 100));
    return 0;
}