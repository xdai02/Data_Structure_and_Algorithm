def is_valid_bracket(bracket):
    stack = []

    for c in bracket:
        if c == "(" or c == "[" or c == "{":
            stack.append(c)
        else:
            if len(stack) == 0:
                return False
            else:
                top = stack.pop()
                if (top == "(" and c != ")") or (top == "[" and c != "]") or (top == "{" and c != "}"):
                    return False
    return len(stack) == 0

brackets = [
    "()",
    "()[]{}",
    "(]",
    "([)]",
    "{[]}",
]

for bracket in brackets:
    print(bracket, ":", is_valid_bracket(bracket))