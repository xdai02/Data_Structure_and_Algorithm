def heap_sort(lst):
    for i in range(len(lst) // 2, -1, -1):
        heapify(lst, i, len(lst))

    for i in range(len(lst) - 1, 0, -1):
        lst[0], lst[i] = lst[i], lst[0]
        heapify(lst, 0, i)

    return lst

def heapify(lst, index, n):
    child_index = 2 * index + 1
    while child_index < n:
        if child_index + 1 < n and lst[child_index + 1] > lst[child_index]:
            child_index += 1
        if lst[index] >= lst[child_index]:
            break
        lst[index], lst[child_index] = lst[child_index], lst[index]
        index = child_index
        child_index = 2 * index + 1

lst = [5, 8, 6, 3, 9, 2, 7, 4, 10]
heap_sort(lst)
print(lst)