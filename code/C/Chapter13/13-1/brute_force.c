#include <stdio.h>
#include <string.h>

int bruteForce(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0;
    int j = 0;

    while(i < sLen && j < pLen) {
        if(s[i] == p[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if(j == pLen) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    char *s = "BBC ABCDAB ABCDABCDABDE";
    char *p = "ABCDABD";
    printf("%d\n", bruteForce(s, p));
    return 0;
}