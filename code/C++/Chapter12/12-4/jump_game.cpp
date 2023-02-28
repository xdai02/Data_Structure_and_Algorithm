#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool can_jump(vector<int> stones) {
    bool can_jump[stones.size()];
    can_jump[0] = true;

    for (int j = 1; j < (int)stones.size(); j++) {
        can_jump[j] = false;
        for (int i = 0; i < j; i++) {
            if (can_jump[i] && i + stones[i] >= j) {
                can_jump[j] = true;
                break;
            }
        }
    }
    return can_jump[stones.size() - 1];
}

int main() {
    vector<int> stones = {2, 3, 1, 1, 4};
    cout << boolalpha << can_jump(stones) << endl;
    return 0;
}