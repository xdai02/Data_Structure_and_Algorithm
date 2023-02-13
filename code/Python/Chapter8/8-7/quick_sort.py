import random

def quick_sort(lst):
    """Quick Sort (original v1.0)"""
    def partition(start, end):
        pivot = lst[start]

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

    def sort(start, end):
        if start < end:
            pivot_index = partition(start, end)
            sort(start, pivot_index - 1)
            sort(pivot_index + 1, end)

    sort(0, len(lst) - 1)

# def quick_sort(lst):
#     """Quick Sort (optimized v2.0)"""
#     def partition(start, end):
#         pivot_index = random.randint(start, end)
#         lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
#         pivot = lst[start]

#         i = start + 1
#         j = end
#         while i <= j:
#             while i <= j and lst[i] <= pivot:
#                 i += 1
#             while i <= j and lst[j] >= pivot:
#                 j -= 1
#             if i <= j:
#                 lst[i], lst[j] = lst[j], lst[i]
        
#         lst[start], lst[j] = lst[j], lst[start]
#         return j

#     def sort(start, end):
#         if start < end:
#             pivot_index = partition(start, end)
#             sort(start, pivot_index - 1)
#             sort(pivot_index + 1, end)

#     sort(0, len(lst) - 1)

# def quick_sort(lst):
#     """Quick Sort (optimized v2.1)"""
#     def median_of_three(start, end):
#         mid = start + (end - start) // 2

#         if lst[start] > lst[mid]:
#             lst[start], lst[mid] = lst[mid], lst[start]
#         if lst[start] > lst[end]:
#             lst[start], lst[end] = lst[end], lst[start]
#         if lst[mid] > lst[end]:
#             lst[mid], lst[end] = lst[end], lst[mid]
        
#         return mid

#     def partition(start, end):
#         pivot_index = median_of_three(start, end)
#         lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
#         pivot = lst[start]

#         i = start + 1
#         j = end
#         while i <= j:
#             while i <= j and lst[i] <= pivot:
#                 i += 1
#             while i <= j and lst[j] >= pivot:
#                 j -= 1
#             if i <= j:
#                 lst[i], lst[j] = lst[j], lst[i]
        
#         lst[start], lst[j] = lst[j], lst[start]
#         return j

#     def sort(start, end):
#         if start < end:
#             pivot_index = partition(start, end)
#             sort(start, pivot_index - 1)
#             sort(pivot_index + 1, end)

#     sort(0, len(lst) - 1)

# def quick_sort(lst):
#     """Quick Sort (optimized v2.2)"""
#     def insertion_sort(lst):
#         """Binary Insertion Sort"""
#         for i in range(1, len(lst)):
#             temp = lst[i]
#             left = 0
#             right = i - 1

#             while left <= right:
#                 mid = (left + right) // 2
#                 if temp < lst[mid]:
#                     right = mid - 1
#                 else:
#                     left = mid + 1

#             for j in range(i - 1, left - 1, -1):
#                 lst[j + 1] = lst[j]
#             lst[left] = temp
        
#         return lst
    
#     def median_of_three(start, end):
#         mid = start + (end - start) // 2

#         if lst[start] > lst[mid]:
#             lst[start], lst[mid] = lst[mid], lst[start]
#         if lst[start] > lst[end]:
#             lst[start], lst[end] = lst[end], lst[start]
#         if lst[mid] > lst[end]:
#             lst[mid], lst[end] = lst[end], lst[mid]
        
#         return mid

#     def partition(start, end):
#         if end - start <= 10:
#             lst[start:end + 1] = insertion_sort(lst[start:end + 1])
#             return None

#         pivot_index = median_of_three(start, end)
#         lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
#         pivot = lst[start]

#         i = start + 1
#         j = end
#         while i <= j:
#             while i <= j and lst[i] <= pivot:
#                 i += 1
#             while i <= j and lst[j] >= pivot:
#                 j -= 1
#             if i <= j:
#                 lst[i], lst[j] = lst[j], lst[i]
        
#         lst[start], lst[j] = lst[j], lst[start]
#         return j

#     def sort(start, end):
#         if start < end:
#             pivot_index = partition(start, end)
#             if pivot_index is not None:
#                 sort(start, pivot_index - 1)
#                 sort(pivot_index + 1, end)

#     sort(0, len(lst) - 1)

lst = [4, 7, 6, 5, 3, 2, 8, 1]
quick_sort(lst)
print(lst)