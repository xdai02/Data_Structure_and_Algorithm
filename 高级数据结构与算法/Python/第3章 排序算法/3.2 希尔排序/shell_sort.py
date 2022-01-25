def shell_sort(list):
    """
        希尔排序（Shell增量序列）
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

def get_hibbard_sequence(n):
    """
        生成Hibbard序列
        1, 3, 7, 15, 31, 63, ...
    """
    sequence = []
    i = 1
    while i <= n:
        sequence.append(i)
        i = (i << 1) + 1
    sequence.reverse()
    return sequence

def shell_sort_hibbard(lst):
    """
        希尔排序（Hibbard增量序列）
    """
    n = len(lst)
    hibbard = get_hibbard_sequence(n)
    for gap in hibbard:
        for i in range(gap, n):
            j = i
            temp = lst[j]
            while j >= gap:
                if temp < lst[j-gap]:
                    lst[j] = lst[j-gap]
                    j -= gap
                else:
                    break
            lst[j] = temp

def get_sedgewick_sequence(n):
    """
        生成Sedgewick序列
        1, 5, 19, 41, 109, ...
    """
    sequence = []
    i = 0
    while True:
        # 9 * 4^i - 9 * 2^i + 1 ==> 9 * (2^(2*i) - 2^i) + 1
        item = 9 * ((1 << (2 * i)) - (1 << i)) + 1
        if item <= n:
            sequence.append(item)
        else:
            break

        # 4^(i+2) - 3 * 2^(i+2) + 1 ==> 2^(2i+4) - 3 * 2^(i+2) + 1
        item = (1 << (2 * i + 4)) - 3 * (1 << (i + 2)) + 1
        if item <= n:
            sequence.append(item)
        else:
            break
        
        i += 1
    return sequence

def shell_sort_sedgewick(lst):
    """
        希尔排序（Sedgewick增量序列）
    """
    n = len(lst)
    sedgewick = get_sedgewick_sequence(n)
    for gap in sedgewick:
        for i in range(gap, n):
            j = i
            temp = lst[j]
            while j >= gap:
                if temp < lst[j-gap]:
                    lst[j] = lst[j-gap]
                    j -= gap
                else:
                    break
            lst[j] = temp

def main():
    lst = [5, 8, 6, 3, 9, 2, 1, 7]

    # 希尔排序
    shell_sort(lst)

    # Hibbard增量序列
    # shell_sort_hibbard(lst)

    # Sedgewick增量序列
    # shell_sort_sedgewick(lst)

    print(lst)

if __name__ == "__main__":
    main()