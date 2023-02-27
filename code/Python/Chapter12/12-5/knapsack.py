ITEM_NUM = 5
CAPACITY = 20

def get_max_value(weight, value):
    b = [
        [0 for col in range(CAPACITY+1)] 
        for row in range(ITEM_NUM+1)
    ]

    for k in range(1, ITEM_NUM+1):
        for c in range(1, CAPACITY+1):
            if weight[k] > c:
                b[k][c] = b[k-1][c]
            else:
                b[k][c] = max(b[k-1][c-weight[k]] + value[k], b[k-1][c])
    
    return b[ITEM_NUM][CAPACITY]

def main():
    weight = [0, 2, 3, 4, 5, 9]
    value = [0, 3, 4, 5, 8, 10]
    print(get_max_value(weight, value))

if __name__ == "__main__":
    main()