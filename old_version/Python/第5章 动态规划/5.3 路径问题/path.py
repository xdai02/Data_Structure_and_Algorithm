def unique_path(m, n):
    f = [[1] * n] + [[1] + [0] * (n - 1) for _ in range(m - 1)]
    for i in range(1, m):
        for j in range(1, n):
            f[i][j] = f[i-1][j] + f[i][j-1]
    return f[m-1][n-1]

def main():
    print(unique_path(4, 8))

if __name__ == "__main__":
    main()