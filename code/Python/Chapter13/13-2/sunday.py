def sunday(s, p):
    i = 0
    j = 0
    result = 0
    
    while i < len(s) and j < len(p):
        if s[i] == p[j]:
            i += 1
            j += 1
            continue

        idx = result + len(p)
        if idx >= len(s):
            return -1

        k = len(p) - 1
        while k >= 0 and s[idx] != p[k]:
            k -= 1

        i = result
        i += len(p) - k
        result = i
        j = 0

        if result + len(p) > len(s):
            return -1

    return result

s = "bcaitsnaxzfinihao"
p = "nihao"
print(sunday(s, p))