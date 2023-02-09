#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

double calculate(const char *expression) {
    stack_t *stack = stack_create();

    char expr[128];
    strcpy(expr, expression);

    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            stack_push(stack, atof(token));
        } else {
            double right = stack_pop(stack);
            double left = stack_pop(stack);
            switch (token[0]) {
            case '+':
                stack_push(stack, left + right);
                break;
            case '-':
                stack_push(stack, left - right);
                break;
            case '*':
                stack_push(stack, left * right);
                break;
            case '/':
                stack_push(stack, left / right);
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    double result = stack_pop(stack);
    stack_destroy(stack);
    return result;
}

int main() {
    char *expressions[] = {
        "1 2 +",          // 1 + 2 = 3
        "2 3 4 + *",      // 2 * (3 + 4) = 14
        "1 2 + 3 4 + *",  // (1 + 2) * (3 + 4) = 21
        "3 4 2 + * 5 *",  // 3 * (4 + 2) * 5 = 90
        "50 20 - 2 /",    // (50 - 20) / 2 = 15
    };
    int expression_num = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < expression_num; i++) {
        printf("%s = %.2f\n", expressions[i], calculate(expressions[i]));
    }

    return 0;
}