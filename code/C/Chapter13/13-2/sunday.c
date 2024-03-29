#include <stdio.h>
#include <string.h>

int sunday(const char *s, const char *p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i = 0;
    int j = 0;
    int result = 0;

    while (i < s_len && j < p_len) {
        if (s[i] == p[j]) {
            i++;
            j++;
            continue;
        }

        int idx = result + p_len;
        if (idx >= s_len) {
            return -1;
        }

        int k = p_len - 1;
        while (k >= 0 && s[idx] != p[k]) {
            k--;
        }

        i = result;
        i += p_len - k;
        result = i;
        j = 0;

        if (result + p_len > s_len) {
            return -1;
        }
    }

    return result;
}

int main() {
    const char *s = "bcaitsnaxzfinihao";
    const char *p = "nihao";
    printf("%d\n", sunday(s, p));
    return 0;
}