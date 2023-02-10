def fast_exponentiation(x, n):
    if n == 0:
        return 1
    
    if n % 2 == 0:
        half = fast_exponentiation(x, n // 2)
        return half * half
    else:
        half = fast_exponentiation(x, (n - 1) // 2)
        return half * half * x

print(fast_exponentiation(2, 18))