def counting_sort(lst):
    n = len(lst)
    max_elem = max(lst)
    min_elem = min(lst)
    length = max_elem - min_elem + 1
    table = [0] * length

    for i in range(n):
        table[lst[i] - min_elem] += 1
    
    cnt = 0
    for i in range(length):
        while table[i]:
            lst[cnt] = i + min_elem
            cnt += 1
            table[i] -= 1

def main():
    lst = [3, 4, 3, 2, 1, 2, 6, 5, 4, 7]
    counting_sort(lst)
    print(lst)

if __name__ == "__main__":
    main()