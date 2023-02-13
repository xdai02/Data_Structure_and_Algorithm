def insertion_sort(lst):
    """Insertion Sort (original v1.0)"""
    for i in range(1, len(lst)):
        temp = lst[i]
        j = i - 1
        while j >= 0 and temp < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = temp
    
    return lst

# def insertion_sort(lst):
#     """Insertion Sort (optimized v2.0)"""
#     for i in range(1, len(lst)):
#         temp = lst[i]
#         left = 0
#         right = i - 1

#         while left <= right:
#             mid = (left + right) // 2
#             if temp < lst[mid]:
#                 right = mid - 1
#             else:
#                 left = mid + 1

#         for j in range(i - 1, left - 1, -1):
#             lst[j + 1] = lst[j]
#         lst[left] = temp
    
#     return lst

lst = [5, 8, 6, 3, 9, 2, 1, 7]
insertion_sort(lst)
print(lst)