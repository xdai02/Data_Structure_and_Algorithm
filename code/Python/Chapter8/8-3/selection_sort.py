def selection_sort(lst):
    """Selection Sort (original v1.0)"""
    for i in range(len(lst)):
        min_index = i
        for j in range(i + 1, len(lst)):
            if lst[j] < lst[min_index]:
                min_index = j
        lst[i], lst[min_index] = lst[min_index], lst[i]
        
    return lst

# def selection_sort(lst):
#     """Selection Sort (optimized v2.0)"""
#     for i in range(len(lst) // 2):
#         min_index = i
#         max_index = len(lst) - i - 1

#         for j in range(i, len(lst) - i):
#             if lst[j] < lst[min_index]:
#                 min_index = j
#             if lst[j] > lst[max_index]:
#                 max_index = j
            
#         lst[i], lst[min_index] = lst[min_index], lst[i]

#         # In case of i == max_index before swap(lst[i], lst[min_index]), it's now at min_index.
#         if i == max_index:
#             max_index = min_index
        
#         lst[len(lst) - i - 1], lst[max_index] = lst[max_index], lst[len(lst) - i - 1]

#     return lst

lst = [5, 8, 6, 3, 9, 2, 1, 7]
print(selection_sort(lst))