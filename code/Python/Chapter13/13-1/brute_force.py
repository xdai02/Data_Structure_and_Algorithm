def brute_force(s, p):
    s_len = len(s)
    p_len = len(p)
    i = 0
    j = 0

    while i < s_len and j < p_len:
        if s[i] == p[j]:
            i += 1
            j += 1
        else:
            i = i - j + 1
            j = 0
    
    if j == p_len:
        return i - j
    else:
        return -1

def main():
    s = "BBC ABCDAB ABCDABCDABDE"
    p = "ABCDABD"
    print(brute_force(s, p))

if __name__ == "__main__":
    main()