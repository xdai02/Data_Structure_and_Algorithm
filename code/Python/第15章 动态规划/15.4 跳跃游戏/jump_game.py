def can_jump(stone):
    n = len(stone)
    f = [True] + [False] * (n - 1)

    for j in range(1, n):
        for i in range(j):
            if f[i] and i + stone[i] >= j:
                f[j] = True
                break
    return f[n-1]

def main():
    stone = [2, 3, 1, 1, 4]
    print(can_jump(stone))

if __name__ == "__main__":
    main()