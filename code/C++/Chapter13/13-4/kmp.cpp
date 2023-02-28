#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<int> get_nexts(const string p) {
    vector<int> next = vector<int>(p.size(), 0);
    int j = 0;

    for (int i = 2; i < (int)p.size(); i++) {
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

int kmp(const string s, const string p) {
    vector<int> next = get_nexts(p);
    int j = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != p[j]) {
            j = next[j];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == (int)p.size()) {
            return i - p.size() + 1;
        }
    }

    return -1;
}

int main() {
    string s = "GTGTGAGCTGGTGTGTGCFAA";
    string p = "GTGTGCF";
    cout << kmp(s, p) << endl;
    return 0;
}
