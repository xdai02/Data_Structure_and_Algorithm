def path(row, col):
    path = [[1] * col] + [[1] + [0] * (col - 1) for _ in range(row - 1)]
    for i in range(1, row):
        for j in range(1, col):
            path[i][j] = path[i - 1][j] + path[i][j - 1]
    return path[row - 1][col - 1]

print(path(4, 8))