#include <iostream>
#include <string>

using namespace std;

int sunday(const string s, const string p) {
    int s_len = s.size();
    int p_len = p.size();
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
    string s = "bcaitsnaxzfinihao";
    string p = "nihao";
    cout << sunday(s, p) << endl;
    return 0;
}