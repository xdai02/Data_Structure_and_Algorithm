#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

// 顺序栈
typedef struct Stack {
    dataType *data;         // 数据域
    int top;                // 栈顶
    int max;                // 栈容量
} Stack;

/**
 * @brief  初始化栈
 * @param  size: 栈容量
 * @retval 栈指针
 */
Stack* init(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if(!stack) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    stack->data = (dataType *)malloc(size * sizeof(dataType));
    if(!stack->data) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return NULL;
    }
    stack->top = -1;
    stack->max = size;
    return stack;
}

/**
 * @brief  判断栈是否已满
 * @param  stack: 栈指针
 * @retval 满栈返回true，未满返回false
 */
bool isFull(Stack *stack) {
    return stack->top == stack->max - 1;
}

/**
 * @brief  判断栈是否为空
 * @param  stack: 栈指针
 * @retval 空栈返回true，非空返回false
 */
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

/**
 * @brief  入栈
 * @param  stack: 栈指针
 * @param  val: 入栈元素
 * @retval 入栈成功返回true，失败返回false
 */
bool push(Stack *stack, dataType val) {
    if(isFull(stack)) {
        return false;
    }
    stack->data[++stack->top] = val;
    return true;
}

/**
 * @brief  出栈
 * @note   可能引发异常
 * @param  stack: 栈指针
 * @retval 出栈元素
 */
dataType pop(Stack *stack) {
    if(isEmpty(stack)) {
        fprintf(stderr, "Error: empty stack.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

/**
 * @brief  查看栈顶元素
 * @note   可能引发异常
 * @param  stack: 栈指针
 * @retval 栈顶元素
 */
dataType peek(Stack *stack) {
    if(isEmpty(stack)) {
        fprintf(stderr, "Error: empty stack.\n");
        exit(1);
    }
    return stack->data[stack->top];
}

/**
 * @brief  销毁栈
 * @param  stack: 栈指针
 */
void destroyStack(Stack *stack) {
    if(!stack) {
        return;
    }
    free(stack->data);
    free(stack);
    stack->data = NULL;
    stack = NULL;
}

int main() {
    Stack *s = init(5);

    push(s, 1);                 // 底 [1] 顶
    push(s, 2);                 // 底 [1, 2] 顶
    push(s, 3);                 // 底 [1, 2, 3] 顶
    printf("%d\n", peek(s));    // 3
    
    while(!isEmpty(s)) {
        printf("%d\n", pop(s));
    }

    destroyStack(s);
    return 0;
}
