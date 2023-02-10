#include <iostream>
#include <string>

using namespace std;

string big_int_add(string num1, string num2) {
    // pad the shorter number with leading zeros
    if (num1.size() < num2.size()) {
        num1.insert(0, num2.size() - num1.size(), '0');
    } else {
        num2.insert(0, num1.size() - num2.size(), '0');
    }

    string result;
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
        int digit_sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = digit_sum / 10;
        int digit = digit_sum % 10;
        result.insert(0, 1, digit + '0');
    }

    if (carry > 0) {
        result.insert(0, 1, carry + '0');
    }
    return result;
}

int main() {
    cout << big_int_add("426709752318", "95481253129") << endl;
    return 0;
}