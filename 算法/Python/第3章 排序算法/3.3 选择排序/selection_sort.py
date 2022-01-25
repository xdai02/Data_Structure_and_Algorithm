def selection_sort(list):
    """
        选择排序
        Args:
            list (list): 待排序列表
    """
    n = len(list)
    for i in range(n-1):
        minIndex = i
        for j in range(i+1, n):
            if list[j] < list[minIndex]:
                minIndex = j
        if i != minIndex:
            list[i], list[minIndex] = list[minIndex], list[i]

def selection_sort_optimize(lst):
    left = 0
    right = len(lst) - 1
    while left < right:
        min = left
        max = right
        for i in range(left, right+1):
            if lst[i] < lst[min]:
                min = i
            if lst[i] > lst[max]:
                max = i
        lst[max], lst[right] = lst[right], lst[max]
        # 考虑特殊情况，最小值在最右位置
        if min == right:
            min = max
        lst[min], lst[left] = lst[left], lst[min]
        left += 1
        right -= 1

def main():
    list = [5, 8, 6, 3, 9, 2, 1, 7]
    print("排序前：" + str(list))
    
    # 未优化
    selection_sort(list)
    # 优化
    selection_sort_optimize(list)
    
    print("排序后：" + str(list))

if __name__ == "__main__":
    main()