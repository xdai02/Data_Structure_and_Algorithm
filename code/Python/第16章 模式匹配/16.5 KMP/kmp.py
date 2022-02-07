def get_nexts(p):
    n = len(p)
    next = [0] * n
    j = 0
    for i in range(2, n):
        while j != 0 and p[j] != p[i-1]:
            j = next[j]
        if p[j] == p[i-1]:
            j += 1
        next[i] = j
    return next

def kmp(s, p):
    next = get_nexts(p)
    j = 0
    for i in range(len(s)):
        while j > 0 and s[i] != p[j]:
            j = next[j]
        if s[i] == p[j]:
            j += 1
        if j == len(p):
            return i - len(p) + 1
    return -1

def main():
    s = "ATGTGAGCTGGTGTGTGCFAA"
    p = "GTGTGCF"
    print(kmp(s, p))

if __name__ == "__main__":
    main()