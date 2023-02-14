INSERTION_SORT_THRESHOLD = 10

def insertion_sort(lst):
    """Binary Insertion Sort"""
    for i in range(1, len(lst)):
        temp = lst[i]
        left = 0
        right = i - 1

        while left <= right:
            mid = (left + right) // 2
            if temp < lst[mid]:
                right = mid - 1
            else:
                left = mid + 1

        for j in range(i - 1, left - 1, -1):
            lst[j + 1] = lst[j]
        lst[left] = temp
    
    return lst

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

# def merge_sort(lst):
#     """Merge Sort (optimized v2.0)"""
#     if len(lst) <= INSERTION_SORT_THRESHOLD:
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

lst = [39, 27, 43, 3, 9, 82, 10]
merge_sort(lst)
print(lst)