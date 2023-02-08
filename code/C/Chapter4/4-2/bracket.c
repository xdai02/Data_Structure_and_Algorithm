#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool is_valid_bracket(char *bracket) {
    stack_t *stack = stack_create();

    int i = 0;
    while (bracket[i] != '\0') {
        char c = bracket[i];

        if (c == '(' || c == '[' || c == '{') {
            stack_push(stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack_is_empty(stack)) {
                return false;
            }
            char top = stack_pop(stack);
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
        i++;
    }

    return stack_is_empty(stack);
}

int main() {
    char *brackets[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
    };
    int bracket_num = sizeof(brackets) / sizeof(brackets[0]);

    for (int i = 0; i < bracket_num; i++) {
        bool is_valid = is_valid_bracket(brackets[i]);
        if (is_valid) {
            printf("%s: true\n", brackets[i]);
        } else {
            printf("%s: false\n", brackets[i]);
        }
    }

    return 0;
}