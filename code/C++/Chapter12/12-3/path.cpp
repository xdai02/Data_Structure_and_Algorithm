#include <iostream>

using namespace std;

int path(int row, int col) {
    int path[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || j == 0) {
                path[i][j] = 1;
            } else {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
    }
    return path[row - 1][col - 1];
}

int main() {
    cout << path(4, 8) << endl;
    return 0;
}