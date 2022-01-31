def bucket_sort(lst):
    n = len(lst)
    max_elem = max(lst)
    min_elem = min(lst)
    diff = max_elem - min_elem

    # 创建桶
    bucket_num = n
    buckets = [[] for _ in range(bucket_num)]

    # 遍历列表，把元素放入对应桶中
    for i in range(n):
        # 计算当前元素所放置的桶号
        num = (lst[i] - min_elem) // (diff // (bucket_num - 1))
        buckets[num].append(lst[i])

    # 桶内排序
    for i in range(bucket_num):
        buckets[i].sort()
    
    # 取出元素
    cnt = 0
    for bucket in buckets:
        for data in bucket:
            lst[cnt] = data
            cnt += 1

def main():
    lst = [4, 6, 23, 3, 21, 8, 41, 10]
    bucket_sort(lst)
    print(lst)

if __name__ == "__main__":
    main()