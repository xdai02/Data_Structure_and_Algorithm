#include <stdio.h>

void count(int head, int foot) {
    for (int chicken = 0; chicken <= head; chicken++) {
        int rabbit = head - chicken;
        if (chicken * 2 + rabbit * 4 == foot) {
            printf("Chicken: %d, Rabbit: %d\n", chicken, rabbit);
        }
    }
}

int main() {
    count(35, 94);
    return 0;
}