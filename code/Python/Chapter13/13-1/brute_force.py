def brute_force(s, p):
    i = 0
    j = 0

    while i < len(s) and j < len(p):
        if s[i] == p[j]:
            i += 1
            j += 1
        else:
            i = i - j + 1
            j = 0
    
    if j == len(p):
        return i - j
    else:
        return -1

s = "BBC ABCDAB ABCDABCDABDE"
p = "ABCDABD"
print(brute_force(s, p))