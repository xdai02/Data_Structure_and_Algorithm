def counting_sort(lst):
    if len(lst) == 0:
        return lst

    max_val = max(lst)
    min_val = min(lst)

    counts = [0] * (max_val - min_val + 1)
    for elem in lst:
        counts[elem - min_val] += 1
    
    lst.clear()
    for i in range(len(counts)):
        lst.extend([i + min_val] * counts[i])
    
    return lst

lst = [95, 94, 91, 98, 99, 90, 99, 93, 91, 92]
counting_sort(lst)
print(lst)