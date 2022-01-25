def hash(s):
    hash_code = 0
    for c in s:
        hash_code += ord(c) - ord('a')
    return hash_code

def next_hash(s, hash, start, n):
    hash -= ord(s[start]) - ord('a')
    hash += ord(s[start + n]) - ord('a')
    return hash

def match(s, p):
    return s == p

def rk(s, p):
    s_len = len(s)
    p_len = len(p)

    s_hash = hash(s[0:p_len])       # 文本串子串哈希值
    p_hash = hash(p)                # 模式串哈希值

    for i in range(s_len - p_len + 1):
        if s_hash == p_hash:
            if match(s[i:i+p_len], p):
                return i
        
        if i < s_len - p_len:
            s_hash = next_hash(s, s_hash, i, p_len)

    return -1

def main():
    s = "a simple example"
    p = "ample"
    print(rk(s, p))

if __name__ == "__main__":
    main()