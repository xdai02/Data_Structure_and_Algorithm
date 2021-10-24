import stack

def priority(op):
    """
        运算符的优先级
        乘除法优先级高于加减法
        Args:
            op (str): 运算符
        Returns:
            (int): 优先级
    """
    if op == "*" or op == "/":
        return 2
    elif op == "+" or op == "-":
        return 1
    else:
        return 0

def infix_to_postfix(exp):
    """
        中缀表达式转换后缀表达式
        转换后的后缀表达式操作数之前带空格
        Args:
            exp (str): 中缀表达式
        Returns:
            (str): 后缀表达式
    """
    postfix = ""    # 保存生成的后缀表达式
    s = stack.Stack()

    number = ""
    for ch in exp:
        # 如果是数字，保存每一位数字
        if ch.isdigit():
            number += ch
            continue
        
        # 如果读取一个完整数字，直接输出
        if len(number) > 0:
            postfix += number + " "
            number = ""
        
        # 空格忽略
        if ch == " ":
            continue
        
        # 如果是运算符，并且空栈，则直接入栈
        if s.is_empty():
            s.push(ch)
        # 如果遇到左括号，将其放入栈中
        elif ch == "(":
            s.push(ch)
        # 如果遇到右括号，则一直出栈并输出，直到遇到左括号为止
        # 注意，左括号只出栈并不输出
        elif ch == ")":
            while s.peek() != "(":
                postfix += s.pop() + " "
            s.pop()
        # 如果遇到任何其它的运算符，如果为栈为空，则直接入栈
        # 否则从栈中出栈元素并输出，直到遇到优先级更低的元素（或者栈为空）位置
        # 在出栈完这些元素后，再将当前遇到的运算符入栈
        # 有一点需要注意，只有在遇到右括号的情况下才将左括号出栈，其它情况都不会出栈左括号
        else:
            while not s.is_empty() and priority(ch) <= priority(s.peek()):
                postfix += s.pop() + " "
            s.push(ch)
    
    if len(number) > 0:
        postfix += number + " "
        number = ""
    
    while not s.is_empty():
        postfix += s.pop() + " "
    
    return postfix.rstrip()

def calculate(postfix):
    """
    表达式求值
    Args:
        postfix (str): 后缀表达式
    Returns:
        (int): 表达式结果
    """
    s = stack.Stack()

    tokens = postfix.split()
    for token in tokens:
        # 数字则入栈
        try:
            s.push(int(token))
        # 运算符则出栈2次，将计算结果入栈
        except ValueError:
            num2 = s.pop()
            num1 = s.pop()
            if token == '+':
                s.push(num1 + num2)
            elif token == '-':
                s.push(num1 - num2)
            elif token == '*':
                s.push(num1 * num2)
            elif token == '/':
                s.push(int(num1 / num2))
    return s.pop()

def main():
    exp = input("Enter expression: ")
    postfix = infix_to_postfix(exp)
    print("Postfix expression: %s" % postfix)
    print("Result: %d" % calculate(postfix))

if __name__ == "__main__":
    main()