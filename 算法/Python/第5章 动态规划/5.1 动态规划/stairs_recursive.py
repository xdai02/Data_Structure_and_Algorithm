def climb_stairs(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    return climb_stairs(n-1) + climb_stairs(n-2)

def main():
    print(climb_stairs(10))

if __name__ == '__main__':
    main()