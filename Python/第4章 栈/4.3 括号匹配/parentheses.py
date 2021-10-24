def valid_parentheses(s):
    if len(s) % 2 == 1:
        return False
    
    pairs = {")": "(", "]": "[", "}": "{"}
    stack = list()
    for paren in s:
        if paren in pairs:
            if not stack or stack[-1] != pairs[paren]:
                return False
            stack.pop()
        else:
            stack.append(paren)

    return not stack

def main():
    parentheses = ["()", "()[]{}", "(]", "([)]", "{[]}"]
    for s in parentheses:
        print(s, ":", valid_parentheses(s))

if __name__ == "__main__":
    main()