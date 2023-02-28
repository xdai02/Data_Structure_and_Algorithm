def can_jump(stones):
    can_jump = [True] + [False] * (len(stones) - 1)

    for j in range(1, len(stones)):
        for i in range(j):
            if can_jump[i] and i + stones[i] >= j:
                can_jump[j] = True
                break
    return can_jump[len(stones) - 1]

stones = [2, 3, 1, 1, 4]
print(can_jump(stones))