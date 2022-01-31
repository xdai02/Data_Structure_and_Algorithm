def cocktail_sort_1(lst):
    n = len(lst)
    for i in range(n // 2):
        # 从左向右
        is_sorted = True        # 标记当前轮是否有序
        for j in range(i, n-i-1):
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
                is_sorted = False   # 发生交换
        if is_sorted:
            break
        
        # 从右向左
        is_sorted = True
        for j in range(n-i-1, i, -1):
            if lst[j] < lst[j-1]:
                lst[j], lst[j-1] = lst[j-1], lst[j]
                is_sorted = False
        if is_sorted:
            break

def cocktail_sort_2(lst):
    n = len(lst)
    last_left = 0           # 左侧最后一次交换位置
    last_right = 0          # 右侧最后一次交换位置
    left_border = 0         # 无序区左边界
    right_border = n - 1    # 无序区右边界

    for i in range(n // 2):
        # 从左向右
        is_sorted = True        # 标记当前轮是否有序
        for j in range(left_border, right_border):
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
                is_sorted = False   # 发生交换
                last_right = j
        if is_sorted:
            break
        right_border = last_right
        
        # 从右向左
        is_sorted = True
        for j in range(right_border, left_border, -1):
            if lst[j] < lst[j-1]:
                lst[j], lst[j-1] = lst[j-1], lst[j]
                is_sorted = False
                last_left = j
        if is_sorted:
            break
        left_border = last_left

def main():
    lst = [2, 3, 4, 5, 6, 7, 8, 1]

    # 未优化
    cocktail_sort_1(lst)

    # 优化
    # cocktail_sort_2(lst)

    print(lst)

if __name__ == "__main__":
    main()