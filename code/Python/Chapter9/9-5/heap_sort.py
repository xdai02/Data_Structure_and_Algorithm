def down_adjust(lst, parent_index, length):
    """
        下沉调整
        Args:
            lst (list): 待调整的堆
            parent_index (int): 要下沉的父结点
            length (int): 堆的有效大小
    """
    # 保存父结点的值，用于最后的赋值
    temp = lst[parent_index]
    child_index = 2 * parent_index + 1

    while child_index < length:
        # 如果有右孩子，且右孩子大于左孩子的值，则定位到右孩子
        if child_index + 1 < length and lst[child_index + 1] > lst[child_index]:
            child_index += 1
        # 如果父结点小于任何一个孩子的值，直接跳出
        if temp >= lst[child_index]:
            break
        # 无需真正交换，单向赋值即可
        lst[parent_index] = lst[child_index]
        parent_index = child_index
        child_index = 2 * child_index + 1
    
    lst[parent_index] = temp

def heap_sort(lst):
    """
        堆排序
        Args:
            lst (list): 待调整的堆
    """
    n = len(lst)
    # 把无序数组构建成二叉堆
    for i in range((n-2)//2, -1, -1):
        down_adjust(lst, i, n)
    
    # 循环删除堆顶元素，移到数组尾部，调节堆产生新的堆顶
    for i in range(n-1, 0, -1):
        # 最后一个元素和第一个元素交换
        lst[i], lst[0] = lst[0], lst[i]
        # 下沉调整最大堆
        down_adjust(lst, 0, i)

def main():
    lst = [5, 8, 6, 3, 9, 2, 1, 7]
    heap_sort(lst)
    print(lst)

if __name__ == "__main__":
    main()