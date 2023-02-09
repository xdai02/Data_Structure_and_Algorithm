def calculate(expression):
    stack = []
    tokens = expression.split()

    for token in tokens:
        if token in "+-*/":
            right = stack.pop()
            left = stack.pop()
            if token == "+":
                stack.append(left + right)
            elif token == "-":
                stack.append(left - right)
            elif token == "*":
                stack.append(left * right)
            elif token == "/":
                stack.append(left / right)
        else:
            stack.append(int(token))
    
    return stack.pop()

expressions = [
    "1 2 +",            # 1 + 2 = 3
    "2 3 4 + *",        # 2 * (3 + 4) = 14
    "1 2 + 3 4 + *",    # (1 + 2) * (3 + 4) = 21
    "3 4 2 + * 5 *",    # 3 * (4 + 2) * 5 = 90
    "50 20 - 2 /",      # (50 - 20) / 2 = 15
]

for expression in expressions:
    print(expression, "=", calculate(expression))