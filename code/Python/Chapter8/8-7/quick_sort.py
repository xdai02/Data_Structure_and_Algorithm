import random

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

def partition(lst, start, end, pivot):
    i = start + 1
    j = end
    while i <= j:
        while i <= j and lst[i] <= pivot:
            i += 1
        while i <= j and lst[j] >= pivot:
            j -= 1
        if i <= j:
            lst[i], lst[j] = lst[j], lst[i]
    
    lst[start], lst[j] = lst[j], lst[start]
    return j
    
def median_of_three(lst, start, end):
    mid = start + (end - start) // 2

    if lst[start] > lst[mid]:
        lst[start], lst[mid] = lst[mid], lst[start]
    if lst[start] > lst[end]:
        lst[start], lst[end] = lst[end], lst[start]
    if lst[mid] > lst[end]:
        lst[mid], lst[end] = lst[end], lst[mid]
    
    return mid

def quick_sort(lst):
    """Quick Sort (original v1.0)"""
    def sort(start, end):
        if start < end:
            pivot = lst[start]

            pivot_index = partition(lst, start, end, pivot)
            sort(start, pivot_index - 1)
            sort(pivot_index + 1, end)

    sort(0, len(lst) - 1)
    return lst

# def quick_sort(lst):
#     """Quick Sort (optimized v2.0)"""
#     def sort(start, end):
#         if start < end:
#             pivot_index = random.randint(start, end)
#             lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
#             pivot = lst[start]

#             pivot_index = partition(lst, start, end, pivot)
#             sort(start, pivot_index - 1)
#             sort(pivot_index + 1, end)

#     sort(0, len(lst) - 1)
#     return lst

# def quick_sort(lst):
#     """Quick Sort (optimized v2.1)"""
#     def sort(start, end):
#         if start < end:
#             pivot_index = median_of_three(lst, start, end)
#             lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
#             pivot = lst[start]

#             pivot_index = partition(lst, start, end, pivot)
#             sort(start, pivot_index - 1)
#             sort(pivot_index + 1, end)

#     sort(0, len(lst) - 1)
#     return lst

# def quick_sort(lst):
#     """Quick Sort (optimized v2.2)"""
#     def sort(start, end):
#         if end - start <= INSERTION_SORT_THRESHOLD:
#             lst[start:end + 1] = insertion_sort(lst[start:end + 1])
#             return

#         pivot_index = median_of_three(lst, start, end)
#         lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
#         pivot = lst[start]

#         pivot_index = partition(lst, start, end, pivot)
#         sort(start, pivot_index - 1)
#         sort(pivot_index + 1, end)

#     sort(0, len(lst) - 1)
#     return lst

lst = [4, 7, 6, 5, 3, 2, 8, 1]
quick_sort(lst)
print(lst)