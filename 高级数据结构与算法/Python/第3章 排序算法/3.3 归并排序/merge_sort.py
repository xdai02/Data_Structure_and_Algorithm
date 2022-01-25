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

def merge(lst, start, mid, end, temp):
    i = start
    j = mid + 1
    k = 0

    while i <= mid and j <= end:
        if lst[i] <= lst[j]:
            temp[k] = lst[i]
            k += 1
            i += 1
        else:
            temp[k] = lst[j]
            k += 1
            j += 1

    while i <= mid:
        temp[k] = lst[i]
        k += 1
        i += 1
    while j <= end:
        temp[k] = lst[j]
        k += 1
        j += 1

    for i in range(k):
        lst[start+i] = temp[i]

def merge_sort_worker(lst, start, end, temp):
    # 列表长度小于10时，采用二分插入排序
    if end - start <= 10:
        binary_insertion_sort(lst, start, end)
        return
    if start < end:
        mid = start + (end - start) // 2
        merge_sort_worker(lst, start, mid, temp)
        merge_sort_worker(lst, mid+1, end, temp)
        # 避免不必要的合并
        if lst[mid] <= lst[mid+1]:
            return
        merge(lst, start, mid, end, temp)

def merge_sort(lst):
    n = len(lst)
    temp = [0] * n      # 临时列表
    merge_sort_worker(lst, 0, n-1, temp)

def main():
    lst = [5, 8, 6, 3, 9, 2, 1, 7]
    merge_sort(lst)
    print(lst)

if __name__ == "__main__":
    main()