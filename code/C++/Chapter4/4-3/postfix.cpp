#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

double calculate(const string expression) {
    stack<double> s;

    stringstream ss(expression);
    string token;
    while (ss >> token) {
        if (token == "+") {
            double right = s.top();
            s.pop();
            double left = s.top();
            s.pop();
            s.push(left + right);
        } else if (token == "-") {
            double right = s.top();
            s.pop();
            double left = s.top();
            s.pop();
            s.push(left - right);
        } else if (token == "*") {
            double right = s.top();
            s.pop();
            double left = s.top();
            s.pop();
            s.push(left * right);
        } else if (token == "/") {
            double right = s.top();
            s.pop();
            double left = s.top();
            s.pop();
            s.push(left / right);
        } else {
            s.push(stod(token));
        }
    }

    return s.top();
}

int main() {
    string expressions[] = {
        "1 2 +",          // 1 + 2 = 3
        "2 3 4 + *",      // 2 * (3 + 4) = 14
        "1 2 + 3 4 + *",  // (1 + 2) * (3 + 4) = 21
        "3 4 2 + * 5 *",  // 3 * (4 + 2) * 5 = 90
        "50 20 - 2 /",    // (50 - 20) / 2 = 15
    };

    for (string expression : expressions) {
        cout << expression << " = " << calculate(expression) << endl;
    }

    return 0;
}