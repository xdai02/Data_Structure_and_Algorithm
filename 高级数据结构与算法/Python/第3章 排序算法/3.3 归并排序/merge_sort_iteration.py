def merge_sort(lst):
    n = len(lst)
    temp = [0] * n
    pos = 0     # 临时列表的下标
    left1 = left2 = 0       # 左子数组边界
    right1 = right2 = 0     # 右子数组边界

    i = 1
    while i < n:
        left1 = 0
        while left1 < n - i:
            # 设置子数组边界
            right1 = left2 = left1 + i
            right2 = left2 + i

            # 防止右边界越界
            if right2 > n:
                right2 = n
            
            pos = 0
            while left1 < left2 and right1 < right2:
                if lst[left1] < lst[right1]:
                    temp[pos] = lst[left1]
                    pos += 1
                    left1 += 1
                else:
                    temp[pos] = lst[right1]
                    pos += 1
                    right1 += 1
            
            while left1 < left2:
                right1 -= 1
                left2 -= 1
                lst[right1] = lst[left2]

            # 将排好序的部分保存回数组
            while pos > 0:
                right1 -= 1
                pos -= 1
                lst[right1] = temp[pos]

            left1 = right2

        i *= 2

def main():
    lst = [5, 8, 6, 3, 9, 2, 1, 7]
    merge_sort(lst)
    print(lst)

if __name__ == "__main__":
    main()