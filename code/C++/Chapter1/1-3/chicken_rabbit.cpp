#include <iostream>

using namespace std;

void count(int head, int foot) {
    for (int chicken = 0; chicken <= head; chicken++) {
        int rabbit = head - chicken;
        if (chicken * 2 + rabbit * 4 == foot) {
            cout << "Chicken: " << chicken << ", Rabbit: " << rabbit << endl;
        }
    }
}

int main() {
    count(35, 94);
    return 0;
}