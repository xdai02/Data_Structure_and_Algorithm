#include <stdio.h>
#include <string.h>

int sunday(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0;
    int j = 0;
    int result = 0;

    while(i < sLen && j < pLen) {
        if(s[i] == p[j]) {
            i++;
            j++;
            continue;
        }

        int idx = result + pLen;
        if(idx >= sLen) {
            return -1;
        }

        int k = pLen - 1;
        while(k >= 0 && s[idx] != p[k]) {
            k--;
        }

        i = result;
        i += pLen - k;
        result = i;
        j = 0;

        if(result + pLen > sLen) {
            return -1;
        }
    }

    return result;
}

int main() {
    char *s = "a simple example";
    char *p = "ample";
    printf("%d\n", sunday(s, p));
    return 0;
}