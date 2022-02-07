def sunday(s, p):
    s_len = len(s)
    p_len = len(p)
    i = 0
    j = 0
    result = 0
    
    while i < s_len and j < p_len:
        if s[i] == p[j]:
            i += 1
            j += 1
            continue

        idx = result + p_len
        if idx >= s_len:
            return -1

        k = p_len - 1
        while k >= 0 and s[idx] != p[k]:
            k -= 1

        i = result
        i += p_len - k
        result = i
        j = 0

        if result + p_len > s_len:
            return -1

    return result

def main():
    s = "a simple example"
    p = "ample"
    print(sunday(s, p))

if __name__ == "__main__":
    main()