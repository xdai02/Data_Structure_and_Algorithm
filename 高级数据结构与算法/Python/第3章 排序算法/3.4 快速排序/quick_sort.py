import random

def binary_insertion_sort(lst, left, right):
    for i in range(left+1, right+1):
        temp = lst[i]
        start = left
        end = i - 1
        while start <= end:
            mid = start + (end - start) // 2
            if lst[mid] > temp:
                end = mid - 1
            else:
                start = mid + 1
        j = i - 1
        while j > end:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = temp

def select_random_pivot(lst, start, end):
    """
        选择基准值（随机）
    """
    pos = random.randint(start, end)
    lst[pos], lst[start] = lst[start], lst[pos]
    return lst[start]

def select_median_pivot(lst, start, end):
    """
        选择基准值（三数取中）
    """
    mid = start + (end - start) // 2
    if lst[mid] > lst[end]:
        lst[mid], lst[end] = lst[end], lst[mid]
    if lst[start] > lst[end]:
        lst[start], lst[end] = lst[end], lst[start]
    if lst[mid] > lst[start]:
        lst[mid], lst[start] = lst[start], lst[mid]
    # 此时arr[mid] <= arr[start] <= arr[end]
    return lst[start]

def gather(lst, start, end, pivot_pos):
    """
        聚集相等基准值
        Args:
            lst (int): 待排序数组
            start (int): 数组开始位置
            end (int): 数组结束位置
            pivot_pos (int): 基准值下标
        Return:
            Tuple (int, int): 基准值左右边界
    """
    if start >= end:
        return
    
    cnt = pivot_pos - 1
    for i in range(pivot_pos-1, start-1, -1):
        if lst[i] == lst[pivot_pos]:
            lst[i], lst[cnt] = lst[cnt], lst[i]
            cnt -= 1
    left = cnt

    cnt = pivot_pos + 1
    for i in range(pivot_pos+1, end+1):
        if lst[i] == lst[pivot_pos]:
            lst[i], lst[cnt] = lst[cnt], lst[i]
            cnt += 1
    right = cnt

    return (left, right)

def quick_sort(lst, start, end):
    if end - start >= 10:
        binary_insertion_sort(lst, start, end)
        return
    
    while start < end:
        i = start
        j = end
        pivot = select_median_pivot(lst, start, end)

        while i < j:
            while i < j and lst[j] > pivot:
                j -= 1
            if i < j:
                lst[i] = lst[j]
                i += 1
            while i < j and lst[i] < pivot:
                i += 1
            if i < j:
                lst[j] = lst[i]
                j -= 1
        
        lst[i] = pivot

        # 聚集与基准值相等元素
        left, right = gather(lst, start, end, i)

        quick_sort(lst, start, left)
        # quick_sort(lst, right, end)     # 消除尾递归
        start = right

def main():
    lst = [5, 8, 6, 3, 9, 2, 1, 7]
    quick_sort(lst, 0, len(lst)-1)
    print(lst)

if __name__ == "__main__":
    main()