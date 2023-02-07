def binary_search(lst, key):
    start = 0
    end = len(lst) - 1
    
    while start <= end:
        mid = (start + end) // 2
        if lst[mid] == key:
            return mid
        elif lst[mid] < key:
            start = mid + 1
        else:
            end = mid - 1
    return -1

lst = [7, 9, 20, 34, 40, 85, 91, 93]
key = 34
print("index =", binary_search(lst, key))