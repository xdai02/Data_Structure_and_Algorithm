def main():
    arr = []
    
    arr.append(1)           # [1]
    arr.append(2)           # [1, 2]
    arr.append(3)           # [1, 2, 3]
    print(arr)

    arr.insert(0, 4)        # [4, 1, 2, 3]
    arr.insert(1, 5)        # [4, 5, 1, 2, 3]
    print(arr)

    arr.pop(3)              # [4, 5, 1, 3]
    arr.pop(2)              # [4, 5, 3]
    print(arr)

    arr[0] = 6              # [6, 5, 3]
    arr[2] = 7              # [6, 5, 7]
    print(arr)

    print(arr[0])           # 6

if __name__ == "__main__":
    main()