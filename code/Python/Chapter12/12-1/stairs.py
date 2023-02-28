def climb_recursive(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    return climb_recursive(n - 1) + climb_recursive(n - 2)

def climb_dp(n):
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

print(climb_recursive(10))
print(climb_dp(10))