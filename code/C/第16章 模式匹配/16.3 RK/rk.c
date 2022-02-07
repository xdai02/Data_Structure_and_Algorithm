#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int hash(char *s, int n) {
    int hashCode = 0;
    for(int i = 0; i < n; i++) {
        hashCode += s[i] - 'a';
    }
    return hashCode;
}

int nextHash(char *s, int hash, int start, int n) {
    hash -= s[start] - 'a';
    hash += s[start + n] - 'a';
    return hash;
}

bool match(char *s, char *p, int n) {
    for(int i = 0; i < n; i++) {
        if(s[i] != p[i]) {
            return false;
        }
    }
    return true;
}

int rk(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);

    int sHash = hash(s, pLen);  // 文本串子串哈希值
    int pHash = hash(p, pLen);  // 模式串哈希值

    for(int i = 0; i < sLen - pLen + 1; i++) {
        if(sHash == pHash) {
            if(match(s+i, p, pLen)) {
                return i;
            }
        }

        if(i < sLen - pLen) {
            sHash = nextHash(s, sHash, i, pLen);
        }
    }

    return -1;
}

int main() {
    char *s = "a simple example";
    char *p = "ample";
    printf("%d\n", rk(s, p));
    return 0;
}
