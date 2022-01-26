def reverse(s):
    s = list(s)
    i = 0
    j = len(s) - 1
    while i < j:
        s[i], s[j] = s[j], s[i]
        i += 1
        j -= 1
    return "".join(s)

def main():
    str = "hello"
    print(reverse(str))

if __name__ == "__main__":
    main()