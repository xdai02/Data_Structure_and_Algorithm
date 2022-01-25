def binary_search(list, key):
    """
        二分查找
        Args:
            list (list): 待查找数组
            key (int): 关键字
    """
    start = 0
    end = len(list) - 1
    while start <= end:
        mid = start + (end - start) // 2
        if list[mid] == key:
            return mid
        elif list[mid] < key:
            start = mid + 1
        else:
            end = mid - 1
    return -1

def main():
    list = [7, 9, 20, 34, 40, 85, 91, 93]
    key = 34
    print("%d所在位置：%d" % (key, binary_search(list, key)))

if __name__ == "__main__":
    main()