def bubble_sort(list):
    """
        冒泡排序
        Args:
            list (list): 待排序列表
    """
    n = len(list)
    for i in range(n):
        for j in range(n-i-1):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]

def bubble_sort_optimize_1(lst):
    n = len(lst)
    for i in range(n-1):
        has_swapped = False    # 标记是否发生交换
        for j in range(n-i-1):
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
                has_swapped = True     # 发生交换
        # 该轮未发生交换，已经有序
        if not has_swapped:
            return

def bubble_sort_optimize_2(lst):
    n = len(lst)
    length = n - 1      # 内层循环执行次数
    for i in range(n-1):
        has_swapped = False       # 标记是否发生交换
        last = 0        # 标记最后一次发生交换的位置
        for j in range(length):
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
                has_swapped = True     # 发生交换
                last = j
        # 该轮未发生交换，已经有序
        if not has_swapped:
            return
        length = last      # 最后一次发生交换的位置

def main():
    list = [5, 8, 6, 3, 9, 2, 1, 7]
    print("排序前：" + str(list))

    # 未优化
    bubble_sort(list)
    # 第一次优化
    # bubble_sort_optimize_1(list)
    # 第二次优化
    # bubble_sort_optimize_2(list)

    print("排序后：" + str(list))

if __name__ == "__main__":
    main()