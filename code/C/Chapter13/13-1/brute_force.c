#include <stdio.h>
#include <string.h>

int brute_force(const char *s, const char *p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i = 0;
    int j = 0;

    while (i < s_len && j < p_len) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == p_len) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    const char *s = "BBC ABCDAB ABCDABCDABDE";
    const char *p = "ABCDABD";
    printf("%d\n", brute_force(s, p));
    return 0;
}