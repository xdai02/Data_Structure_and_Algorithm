def bubble_sort(lst):
    """Bubble Sort (original v1.0)"""
    for i in range(len(lst) - 1):
        for j in range(len(lst) - 1 - i):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
    
    return lst

# def bubble_sort(lst):
#     """Bubble Sort (optimized v2.0)"""
#     for i in range(len(lst) - 1):
#         swapped = False
#         for j in range(len(lst) - 1 - i):
#             if lst[j] > lst[j + 1]:
#                 lst[j], lst[j + 1] = lst[j + 1], lst[j]
#                 swapped = True
#         if not swapped:
#             break
    
#     return lst

# def bubble_sort(lst):
#     """Bubble Sort (optimized v2.1)"""
#     right = len(lst) - 1
#     for i in range(len(lst) - 1):
#         swapped = False
#         last = 0
#         for j in range(right):
#             if lst[j] > lst[j + 1]:
#                 lst[j], lst[j + 1] = lst[j + 1], lst[j]
#                 swapped = True
#                 last = j
#         if not swapped:
#             break
#         right = last

#     return lst

lst = [5, 8, 6, 3, 9, 2, 1, 7]
bubble_sort(lst)
print(lst)