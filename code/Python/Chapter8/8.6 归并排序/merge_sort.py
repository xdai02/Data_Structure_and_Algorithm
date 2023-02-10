def merge(list, start, mid, end, temp):
    """
        合并
        Args:
            list (list): 待排序列表
            start (int): 开始下标
            mid (int): 中间下标
            end (int): 结束下标
            temp (list): 临时列表
    """
    i = start
    j = mid + 1
    k = 0

    while i <= mid and j <= end:
        if list[i] <= list[j]:
            temp[k] = list[i]
            k += 1
            i += 1
        else:
            temp[k] = list[j]
            k += 1
            j += 1

    while i <= mid:
        temp[k] = list[i]
        k += 1
        i += 1
    while j <= end:
        temp[k] = list[j]
        k += 1
        j += 1

    for i in range(k):
        list[start+i] = temp[i]

def merge_sort(list, start, end, temp):
    """
        归并排序
        Args:
            list (list): 待排序列表
            start (int): 开始下标
            end (int): 结束下标
            temp (list): 临时列表
    """
    if start < end:
        mid = start + (end - start) // 2
        merge_sort(list, start, mid, temp)
        merge_sort(list, mid+1, end, temp)
        merge(list, start, mid, end, temp)

def main():
    list = [5, 8, 6, 3, 9, 2, 1, 7]
    temp = [0] * len(list)       # 临时列表
    print("排序前：" + str(list))
    merge_sort(list, 0, len(list)-1, temp)
    print("排序后：" + str(list))

if __name__ == "__main__":
    main()