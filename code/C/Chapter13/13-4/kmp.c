#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *get_nexts(const char *p) {
    int n = strlen(p);
    int *next = (int *)malloc(sizeof(int) * n);
    memset(next, 0, sizeof(int) * n);
    int j = 0;

    for (int i = 2; i < n; i++) {
        while (j != 0 && p[j] != p[i - 1]) {
            j = next[j];
        }
        if (p[j] == p[i - 1]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

int kmp(const char *s, const char *p) {
    int *next = get_nexts(p);
    int j = 0;
    int s_len = strlen(s);
    int p_len = strlen(p);

    for (int i = 0; i < s_len; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = next[j];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == p_len) {
            free(next);
            return i - p_len + 1;
        }
    }

    free(next);
    return -1;
}

int main() {
    const char *s = "GTGTGAGCTGGTGTGTGCFAA";
    const char *p = "GTGTGCF";
    printf("%d\n", kmp(s, p));
    return 0;
}
