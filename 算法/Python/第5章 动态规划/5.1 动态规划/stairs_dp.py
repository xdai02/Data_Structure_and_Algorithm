def climb_stairs(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    num1 = 1
    num2 = 2
    for _ in range(3, n+1):
        sum = num1 + num2
        num1 = num2
        num2 = sum
    return sum

def main():
    print(climb_stairs(10))

if __name__ == '__main__':
    main()