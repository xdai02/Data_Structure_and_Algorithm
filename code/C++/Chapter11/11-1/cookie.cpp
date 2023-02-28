#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distribute(vector<int> children, vector<int> cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int children_num = children.size();
    int cookies_num = cookies.size();

    int child = 0;
    int cookie = 0;
    while (child < children_num && cookie < cookies_num) {
        if (children[child] <= cookies[cookie]) {
            child++;
        }
        cookie++;
    }
    return child;
}

int main() {
    vector<int> children = {1, 2};
    vector<int> cookies = {1, 2, 3};
    cout << distribute(children, cookies) << endl;
    return 0;
}