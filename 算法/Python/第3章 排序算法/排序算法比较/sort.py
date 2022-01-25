# 对比不同算法对data.txt中50000个整数进行排序的时间

import time

MAX = 50000
FILENAME = "data.txt"       # 数据文件

def read_data(filename):
    """
        从文件读取数据
        Args:
            filename (str): 数据文件
        Returns:
            list: 返回保存数据的列表
    """
    list = []
    i = 0
    with open(filename) as file:
        for line in file:
            list += [int(num) for num in line.split()]
    return list

def save_file(filename, list):
    """
        排序结果保存到文件
        Args:
            filename (str): 文件名
            list (list): 排序后列表
        Returns:
            list: 成功返回True，失败返回False
    """
    with open(filename, "w") as file:
        for num in list:
            file.write(str(num) + "\n")
        return True
    return False

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

def shell_sort(list):
    """
        希尔排序
        Args:
            list (list): 待排序列表
    """
    gap = len(list)
    n = len(list)
    while gap > 1:
        gap //= 2
        for i in range(gap):
            for j in range(i+gap, n, gap):
                temp = list[j]
                k = j - gap
                while k >= 0 and list[k] > temp:
                    list[k+gap] = list[k]
                    k -= gap
                list[k+gap] = temp

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

def down_adjust(list, parent_index, length):
    """
        下沉调整
        Args:
            list (list): 待调整的堆
            parent_index (int): 要下沉的父结点
            length (int): 堆的有效大小
    """
    # 保存父结点的值，用于最后的赋值
    temp = list[parent_index]
    child_index = 2 * parent_index + 1

    while child_index < length:
        # 如果有右孩子，且右孩子大于左孩子的值，则定位到右孩子
        if child_index + 1 < length and list[child_index + 1] > list[child_index]:
            child_index += 1
        # 如果父结点小于任何一个孩子的值，直接跳出
        if temp >= list[child_index]:
            break
        # 无需真正交换，单向赋值即可
        list[parent_index] = list[child_index]
        parent_index = child_index
        child_index = 2 * child_index + 1
    
    list[parent_index] = temp

def heap_sort(list):
    """
        堆排序
        Args:
            list (list): 待调整的堆
    """
    n = len(list)
    # 把无序数组构建成二叉堆
    for i in range((n-2)//2, -1, -1):
        down_adjust(list, i, n)
    
    # 循环删除堆顶元素，移到数组尾部，调节堆产生新的堆顶
    for i in range(n-1, 0, -1):
        # 最后一个元素和第一个元素交换
        list[i], list[0] = list[0], list[i]
        # 下沉调整最大堆
        down_adjust(list, 0, i)

def main():
    # *************** 【冒泡排序】 ***************
    print("开始【冒泡排序】...")
    # list = read_data(FILENAME)
    # start = time.time()
    # bubble_sort(list)
    # end = time.time()
    # running_time = end - start
    # print("\t【冒泡排序】：%.3f秒" % running_time)
    # save_file("bubbleSort.txt", list)
    print("\t【冒泡排序】：超时")

    # *************** 【选择排序】 ***************
    print("开始【选择排序】...")
    # list = read_data(FILENAME)
    # start = time.time()
    # #selection_sort(list)
    # end = time.time()
    # running_time = end - start
    # print("\t【选择排序】：%.3f秒" % running_time)
    # save_file("selectionSort.txt", list)
    print("\t【选择排序】：超时")

    # *************** 【插入排序】 ***************
    print("开始【插入排序】...")
    # list = read_data(FILENAME)
    # start = time.time()
    # #insertion_sort(list)
    # end = time.time()
    # running_time = end - start
    # print("\t【插入排序】：%.3f秒" % running_time)
    # save_file("insertionShell.txt", list)
    print("\t【插入排序】：超时")

    # *************** 【希尔排序】 ***************
    print("开始【希尔排序】...")
    list = read_data(FILENAME)
    start = time.time()
    shell_sort(list)
    end = time.time()
    running_time = end - start
    print("\t【希尔排序】：%.3f秒" % running_time)
    save_file("shellSort.txt", list)

    # *************** 【归并排序】 ***************
    print("开始【归并排序】...")
    temp = [0] * MAX        # 归并排序需要使用的临时数组
    list = read_data(FILENAME)
    start = time.time()
    merge_sort(list, 0, MAX-1, temp)
    end = time.time()
    running_time = end - start
    print("\t【归并排序】：%.3f秒" % running_time)
    save_file("mergeSort.txt", list)

    # *************** 【快速排序】 ***************
    print("开始【快速排序】...")
    list = read_data(FILENAME)
    start = time.time()
    quick_sort(list, 0, MAX-1)
    end = time.time()
    running_time = end - start
    print("\t【快速排序】：%.3f秒" % running_time)
    save_file("quickSort.txt", list)

    # *************** 【堆排序】 ***************
    print("开始【堆排序】...")
    list = read_data(FILENAME)
    start = time.time()
    heap_sort(list)
    end = time.time()
    running_time = end - start
    print("\t【堆排序】：%.3f秒" % running_time)
    save_file("heapSort.txt", list)

if __name__ == "__main__":
    main()