N = 2

def matrix_multiply(a, b):
    c = [
        [0, 0],
        [0, 0]
    ]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                c[i][j] += a[i][k] * b[k][j]
    return c

def matrix_fast_exp(n):
    result = [
        [1, 1],
        [1, 0]
    ]
    M = [
        [1, 1],
        [1, 0]
    ]

    while n > 0:
        if n & 1:
            result = matrix_multiply(result, M)
        M = matrix_multiply(M, M)
        n >>= 1
    
    return result[0][0]

def main():
    for i in range(1, 11):
        print(matrix_fast_exp(i-2), end= ' ')
    print()

if __name__ == "__main__":
    main()