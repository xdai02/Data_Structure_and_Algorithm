def quick_sort(list, start, end):
    """
        快速排序
        Args:
            list (list): 待排序列表
            start (int): 开始下标
            end (int): 结束下标
    """
    if start < end:
        i = start
        j = end
        pivot = list[start]

        while i < j:
            while i < j and list[j] > pivot:
                j -= 1
            if i < j:
                list[i] = list[j]
                i += 1
            while i < j and list[i] < pivot:
                i += 1
            if i < j:
                list[j] = list[i]
                j -= 1
        
        list[i] = pivot
        quick_sort(list, start, i-1)
        quick_sort(list, i+1, end)

def main():
    list = [5, 8, 6, 3, 9, 2, 1, 7]
    print("排序前：" + str(list))
    quick_sort(list, 0, len(list)-1)
    print("排序后：" + str(list))

if __name__ == "__main__":
    main()