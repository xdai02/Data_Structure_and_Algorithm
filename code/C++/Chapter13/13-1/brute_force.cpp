#include <iostream>
#include <string>

using namespace std;

int brute_force(const string s, const string p) {
    int s_len = s.size();
    int p_len = p.size();
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
    string s = "BBC ABCDAB ABCDABCDABDE";
    string p = "ABCDABD";
    cout << brute_force(s, p) << endl;
    return 0;
}