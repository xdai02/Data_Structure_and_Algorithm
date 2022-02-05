def fast_exp(a, n):
    """
        快速幂计算a^n
    """
    result = 1
    while n:
        if n & 1:
            result *= a
        a *= a
        n >>= 1
    return result

def main():
    # 2^18 = 262144
    print(fast_exp(2, 18))

if __name__ == "__main__":
    main()