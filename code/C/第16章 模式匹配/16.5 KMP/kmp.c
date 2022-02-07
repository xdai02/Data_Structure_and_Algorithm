#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getNexts(char *p) {
    int n = strlen(p);
    int *next = (int *)malloc(sizeof(int) * n);
    memset(next, 0, sizeof(int) * n);
    int j = 0;
    for(int i = 2; i < n; i++) {
        while(j != 0 && p[j] != p[i-1]) {
            j = next[j];
        }
        if(p[j] == p[i-1]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

int kmp(char *s, char *p) {
    int *next = getNexts(p);
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);

    for(int i = 0; i < sLen; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = next[j];
        }
        if(s[i] == p[j]) {
            j++;
        }
        if(j == pLen) {
            free(next);
            return i - pLen + 1;
        }
    }

    free(next);
    return -1;
}

int main() {
    char *s = "ATGTGAGCTGGTGTGTGCFAA";
    char *p = "GTGTGCF";
    printf("%d\n", kmp(s, p));
    return 0;
}
