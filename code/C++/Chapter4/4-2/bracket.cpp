#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

bool is_valid_bracket(string bracket) {
    stack<char> stack;

    for (char c : bracket) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    vector<string> brackets = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
    };

    for (string bracket : brackets) {
        cout << bracket << ": " << boolalpha << is_valid_bracket(bracket) << endl;
    }

    return 0;
}