def count_inverses(lst):
    count = 0
    for i in range(len(lst)):
        for j in range(i+1, len(lst)):
            if lst[i] > lst[j]:
                count += 1
    return count

lst = [5, 8, 6, 3, 9, 2, 1, 7]
print(count_inverses(lst))