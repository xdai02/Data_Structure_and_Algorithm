INESRTION_SORT_THRESHOLD = 10

def merge_sort(lst):
    """Merge Sort (original v1.0)"""
    if len(lst) <= 1:
        return lst
    
    mid = len(lst) // 2
    left_half = lst[:mid]
    right_half = lst[mid:]

    merge_sort(left_half)
    merge_sort(right_half)

    i = 0
    j = 0
    k = 0

    while i < len(left_half) and j < len(right_half):
        if left_half[i] < right_half[j]:
            lst[k] = left_half[i]
            i += 1
        else:
            lst[k] = right_half[j]
            j += 1
        k += 1
    
    while i < len(left_half):
        lst[k] = left_half[i]
        i += 1
        k += 1
    
    while j < len(right_half):
        lst[k] = right_half[j]
        j += 1
        k += 1
    
    return lst

# def insertion_sort(lst):
#     """Binary Insertion Sort"""
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

# def merge_sort(lst):
#     """Merge Sort (optimized v2.0)"""
#     if len(lst) <= INESRTION_SORT_THRESHOLD:
#         return insertion_sort(lst)
    
#     mid = len(lst) // 2
#     left_half = lst[:mid]
#     right_half = lst[mid:]

#     left_half = merge_sort(left_half)
#     right_half = merge_sort(right_half)

#     i = 0
#     j = 0
#     k = 0

#     while i < len(left_half) and j < len(right_half):
#         if left_half[i] < right_half[j]:
#             lst[k] = left_half[i]
#             i += 1
#         else:
#             lst[k] = right_half[j]
#             j += 1
#         k += 1
    
#     while i < len(left_half):
#         lst[k] = left_half[i]
#         i += 1
#         k += 1
    
#     while j < len(right_half):
#         lst[k] = right_half[j]
#         j += 1
#         k += 1
    
#     return lst

# def merge_sort(lst):
#     """Merge Sort (optimized v3.0)"""
#     def merge(lst, left, mid, right):
#         n1 = mid - left + 1
#         n2 = right - mid

#         left_half = [0] * n1
#         right_half = [0] * n2

#         for i in range(0, n1):
#             left_half[i] = lst[left + i]
#         for i in range(0, n2):
#             right_half[i] = lst[mid + i + 1]
        
#         i = 0
#         j = 0
#         k = left

#         while i < n1 and j < n2:
#             if left_half[i] < right_half[j]:
#                 lst[k] = left_half[i]
#                 i += 1
#             else:
#                 lst[k] = right_half[j]
#                 j += 1
#             k += 1
        
#         while i < n1:
#             lst[k] = left_half[i]
#             i += 1
#             k += 1
        
#         while j < n2:
#             lst[k] = right_half[j]
#             j += 1
#             k += 1

#     if len(lst) <= INESRTION_SORT_THRESHOLD:
#         return insertion_sort(lst)

#     current_size = 1
#     while current_size < len(lst) - 1:
#         left = 0
#         while left < len(lst) - 1:
#             mid = min(left + current_size - 1, len(lst) - 1)
#             right = min(left + 2 * current_size - 1, len(lst) - 1)
#             merge(lst, left, mid, right)
#             left = right + 1
#         current_size *= 2
    
#     return lst

lst = [39, 27, 43, 3, 9, 82, 10]
merge_sort(lst)
print(lst)