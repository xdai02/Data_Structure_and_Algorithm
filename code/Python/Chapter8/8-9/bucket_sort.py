def bucket_sort(lst):
    if len(lst) == 0:
        return lst
    
    max_val = max(lst)
    min_val = min(lst)
    bucket_size = (max_val - min_val) // len(lst) + 1

    buckets = [[] for _ in range(len(lst))]

    for elem in lst:
        index = (elem - min_val) // bucket_size
        buckets[index].append(elem)
    
    lst.clear()
    for bucket in buckets:
        bucket.sort()
        lst.extend(bucket)
    
    return lst

lst = [18, 11, 28, 45, 23, 49]
bucket_sort(lst)
print(lst)