def insertion_sort(list):
    """
        插入排序
        Args:
            list (list): 待排序列表
    """
    n = len(list)
    for i in range(1, n):
        temp = list[i]
        j = i - 1
        while j >= 0 and temp < list[j]:
            list[j+1] = list[j]
            j -= 1
        list[j+1] = temp

def binary_insertion_sort(lst):
    n = len(lst)
    for i in range(1, n):
        temp = lst[i]
        start = 0
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

def main():
    list = [5, 8, 6, 3, 9, 2, 1, 7]
    print("排序前：" + str(list))
    
    # 未优化
    insertion_sort(list)
    # 优化
    # binary_insertion_sort(list)
    
    print("排序后：" + str(list))

if __name__ == "__main__":
    main()