#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char **data;
    int top;
} Stack;

Stack* init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (char **)malloc(sizeof(char *) * 32);
    for(int i = 0; i < 32; i++) {
        s->data[i] = (char *)malloc(sizeof(char) * 8);
        memset(s->data[i], '\0', sizeof(*s->data[i]));
    }
    s->top = -1;
    return s;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *data) {
    strcpy(s->data[++s->top], data);
}

char* pop(Stack *s) {
    return s->data[s->top--];
}

void deleteStack(Stack *s) {
    for(int i = 0; i < 32; i++) {
        free(s->data[i]);
    }
    free(s->data);
    free(s);
}

char* peek(Stack *s) {
    return s->data[s->top];
}

/**
 * @brief  判断字符串是否为数值
 * @param  s: 待判断字符串
 * @retval 是数值返回true，否则返回false
 */
bool isNumber(char *s) {
    while(*s != '\0') {
        if(!isdigit(*s)) {
            return false;
        }
        s++;
    }
    return true;
}

/**
 * @brief  运算符的优先级
 * @note   乘除法优先级高于加减法
 * @param  op: 运算符
 * @retval 优先级
 */
int priority(char op){
    if(op == '*' || op == '/') {
        return 2;
    } else if(op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief  中缀表达式转换后缀表达式
 * @note   转换后的后缀表达式操作数之前带空格
 * @param  exp: 中缀表达式
 * @retval 后缀表达式
 */
char* infixToPostfix(char *exp) {
    // 保存生成的后缀表达式
    char *postfix = (char *)malloc(sizeof(char) * 128);
    memset(postfix, '\0', sizeof(*postfix));
    Stack *s = init();
    char op[2];
    memset(op, '\0', sizeof(op));

    while(*exp != '\0') {
        // 如果是数字，直接输出
        if(isdigit(*exp)) {
            char number[8];
            int i = 0;
            while(isdigit(*exp)) {
                number[i++] = *exp;
                exp++;
            }
            number[i] = '\0';
            strcat(postfix, number);
            strcat(postfix, " ");
        }

        if(*exp == '\0') {
            break;
        }

        // 空格忽略
        if(*exp == ' ') {
            exp++;
            continue;
        }

        // 如果是运算符，并且空栈，则直接入栈
        if(isEmpty(s)) {
            op[0] = *exp;
            push(s, op);
        }
        // 如果遇到左括号，将其放入栈中
        else if(*exp == '(') {
            op[0] = *exp;
            push(s, op);
        }
        // 如果遇到右括号，则一直出栈并输出，直到遇到左括号为止
        // 注意，左括号只出栈并不输出
        else if(*exp == ')') {
            while(peek(s)[0] != '('){
                strcat(postfix, pop(s));
                strcat(postfix, " ");
            }
            pop(s);
        }
        // 如果遇到任何其它的运算符，如果为栈为空，则直接入栈
        // 否则从栈中出栈元素并输出，直到遇到优先级更低的元素（或者栈为空）位置
        // 在出栈完这些元素后，再将当前遇到的运算符入栈
        // 有一点需要注意，只有在遇到右括号的情况下才将左括号出栈，其它情况都不会出栈左括号
        else {
            while(!isEmpty(s) && priority(*exp) <= priority(peek(s)[0])) {
                strcat(postfix, pop(s));
                strcat(postfix, " ");
            }
            op[0] = *exp;
            push(s, op);
        }
        exp++;
    }

    while(!isEmpty(s)) {
        strcat(postfix, pop(s));
        strcat(postfix, " ");
    }
    postfix[strlen(postfix) - 1] = '\0';

    deleteStack(s);
    return postfix;
}

/**
 * @brief  表达式求值
 * @param  postfix: 后缀表达式
 * @retval 表达式结果
 */
int calculate(char *postfix) {
    int stack[32];
    int top = -1;

    char *s = strtok(postfix, " ");
    while(s) {
        if(isNumber(s)) {       // 数字则入栈
            stack[++top] = atoi(s);
        } else {                // 运算符则出栈2次，将计算结果入栈
            int num2 = stack[top--];
            int num1 = stack[top--];
            if(*s == '+') {
                stack[++top] = num1 + num2;
            } else if(*s == '-') {
                stack[++top] = num1 - num2;
            } else if(*s == '*') {
                stack[++top] = num1 * num2;
            } else if(*s == '/') {
                stack[++top] = num1 / num2;
            }
        }
        s = strtok(NULL, " ");
    }

    return stack[top];
}

int main() {
    char exp[128];

    printf("Enter expression: ");
    gets(exp);

    char *postfix = infixToPostfix(exp);
    printf("Postfix expression: %s\n", postfix);
    printf("Result = %d\n", calculate(postfix));

    free(postfix);
    return 0;
}