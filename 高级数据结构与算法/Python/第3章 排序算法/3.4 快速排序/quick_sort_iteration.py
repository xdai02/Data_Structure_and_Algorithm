import stack

def partition(lst, start, end):
    i = start - 1
    pivot = lst[end]

    for j in range(start, end):
        if lst[j] <= pivot:
            i += 1
            lst[i], lst[j] = lst[j], lst[i]

    lst[i+1], lst[end] = lst[end], lst[i+1]
    return i + 1

def quick_sort(lst, start, end):
    s = stack.Stack()
    s.push(start)
    s.push(end)

    while not s.is_empty():
        right = s.pop()
        left = s.pop()

        index = partition(lst, left, right)
        if index - 1 > left:
            s.push(left)
            s.push(index - 1)
        if index + 1 < right:
            s.push(index + 1)
            s.push(right)

def main():
    lst = [5, 8, 6, 3, 9, 2, 1, 7]
    quick_sort(lst, 0, len(lst)-1)
    print(lst)

if __name__ == "__main__":
    main()