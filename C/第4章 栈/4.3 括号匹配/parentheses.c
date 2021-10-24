#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char pairs(char right) {
    if(right == ')') {
        return '(';
    } else if(right == ']') {
        return '[';
    } else if(right == '}') {
        return '{';
    }
    return 0;
}

bool validParentheses(char *s) {
    int n = strlen(s);
    if(n % 2 == 1) {
        return false;
    }

    int stack[n];
    int top = -1;
    for(int i = 0; i < n; i++) {
        char paren = pairs(s[i]);
        if(paren) {
            if(top == -1 || stack[top] != paren) {
                return false;
            }
            top--;
        } else {
            stack[++top] = s[i];
        }
    }
    return top == -1;
}

int main() {
    char *s[] = {"()", "()[]{}", "(]", "([)]", "{[]}"};
    int n = sizeof(s) / sizeof(char *);

    for(int i = 0; i < n; i++) {
        printf("%s: %s\n", s[i], validParentheses(s[i]) ? "true" : "false");
    }

    return 0;
}