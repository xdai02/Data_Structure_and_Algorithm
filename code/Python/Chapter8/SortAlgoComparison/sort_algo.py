import math

def bubble_sort(lst):
    """Bubble Sort (original v1.0)"""
    for i in range(len(lst) - 1):
        for j in range(len(lst) - 1 - i):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
    
    return lst

def bubble_sort_opt_v1(lst):
    """Bubble Sort (optimized v2.0)"""
    for i in range(len(lst) - 1):
        swapped = False
        for j in range(len(lst) - 1 - i):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                swapped = True
        if not swapped:
            break
    
    return lst

def bubble_sort_opt_v2(lst):
    """Bubble Sort (optimized v2.1)"""
    right = len(lst) - 1
    for i in range(len(lst) - 1):
        swapped = False
        last = 0
        for j in range(right):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                swapped = True
                last = j
        if not swapped:
            break
        right = last

    return lst

def selection_sort(lst):
    """Selection Sort (original v1.0)"""
    for i in range(len(lst)):
        min_index = i
        for j in range(i + 1, len(lst)):
            if lst[j] < lst[min_index]:
                min_index = j
        lst[i], lst[min_index] = lst[min_index], lst[i]
        
    return lst

def selection_sort_opt(lst):
    """Selection Sort (optimized v2.0)"""
    for i in range(len(lst) // 2):
        min_index = i
        max_index = len(lst) - i - 1

        for j in range(i, len(lst) - i):
            if lst[j] < lst[min_index]:
                min_index = j
            if lst[j] > lst[max_index]:
                max_index = j
            
        lst[i], lst[min_index] = lst[min_index], lst[i]

        # In case of i == max_index before swap(lst[i], lst[min_index]), it's now at min_index.
        if i == max_index:
            max_index = min_index
        
        lst[len(lst) - i - 1], lst[max_index] = lst[max_index], lst[len(lst) - i - 1]

    return lst

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

def insertion_sort_opt(lst):
    """Insertion Sort (optimized v2.0)"""
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

def shell_sort(lst):
    """Shell Sort (original v1.0)"""
    gap = len(lst) // 2

    while gap > 0:
        for i in range(gap, len(lst)):
            temp = lst[i]
            j = i
            while j >= gap and lst[j - gap] > temp:
                lst[j] = lst[j - gap]
                j -= gap
            lst[j] = temp
        gap //= 2

    return lst

def shell_sort_opt_hibbard(lst):
    """Shell Sort (Hibbard)"""
    k = int(math.log2(len(lst)))

    while k >= 0:
        gap = 2 ** k - 1
        for i in range(gap, len(lst)):
            temp = lst[i]
            j = i
            while j >= gap and lst[j - gap] > temp:
                lst[j] = lst[j - gap]
                j -= gap
            lst[j] = temp
        k -= 1
    
    return lst

def shell_sort_opt_sedgewick(lst):
    """Shell Sort (Sedgewick)"""
    k = int(math.log2(len(lst) / 3))

    while k >= 0:
        gap = int(4 ** k + 3 * 2 ** (k - 1) + 1)
        for i in range(gap, len(lst)):
            temp = lst[i]
            j = i
            while j >= gap and lst[j - gap] > temp:
                lst[j] = lst[j - gap]
                j -= gap
            lst[j] = temp
        k -= 1

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

def merge_sort_opt_v1(lst):
    """Merge Sort (optimized v2.0)"""
    if len(lst) <= 10:
        return insertion_sort_opt(lst)
    
    mid = len(lst) // 2
    left_half = lst[:mid]
    right_half = lst[mid:]

    left_half = merge_sort_opt_v1(left_half)
    right_half = merge_sort_opt_v1(right_half)

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

def merge_sort_opt_v2(lst):
    """Merge Sort (optimized v3.0)"""
    def merge(lst, left, mid, right):
        n1 = mid - left + 1
        n2 = right - mid

        left_half = [0] * n1
        right_half = [0] * n2

        for i in range(0, n1):
            left_half[i] = lst[left + i]
        for i in range(0, n2):
            right_half[i] = lst[mid + i + 1]
        
        i = 0
        j = 0
        k = left

        while i < n1 and j < n2:
            if left_half[i] < right_half[j]:
                lst[k] = left_half[i]
                i += 1
            else:
                lst[k] = right_half[j]
                j += 1
            k += 1
        
        while i < n1:
            lst[k] = left_half[i]
            i += 1
            k += 1
        
        while j < n2:
            lst[k] = right_half[j]
            j += 1
            k += 1

    if len(lst) <= 10:
        return insertion_sort_opt(lst)

    current_size = 1
    while current_size < len(lst) - 1:
        left = 0
        while left < len(lst) - 1:
            mid = min(left + current_size - 1, len(lst) - 1)
            right = min(left + 2 * current_size - 1, len(lst) - 1)
            merge(lst, left, mid, right)
            left = right + 1
        current_size *= 2
    
    return lst