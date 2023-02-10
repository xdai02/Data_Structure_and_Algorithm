def radix_sort(lst):
    n = len(lst)
    max_elem = max(lst)

    # 创建桶
    bucket_num = 10

    # 从个位开始
    exp = 1
    while max_elem // exp > 0:
        # 创建桶
        buckets = [[] for _ in range(bucket_num)]

        # 把元素放到对应桶中
        for i in range(n):
            num = (lst[i] // exp) % 10
            buckets[num].append(lst[i])
        
        # 按顺序取出元素
        cnt = 0
        for bucket in buckets:
            for data in bucket:
                lst[cnt] = data
                cnt += 1

        exp *= 10

def main():
    lst = [63, 157, 189, 51, 101, 47, 141, 121, 157, 156,
           194, 117, 98, 139, 67, 133, 181, 12, 28, 0, 109]
    radix_sort(lst)
    print(lst)

if __name__ == "__main__":
    main()