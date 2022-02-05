def big_int_mul(num1, num2):
    """
        大整数乘法
        Args:
            num1 (str): 大整数1
            num2 (str): 大整数2
        Returns:
            [str]: 相乘结果
    """
    # 有一个为空，结果为0
    if not num1 or not num2:
        return '0'
    # 终止条件
    elif len(num1) == 1 and len(num2) == 1:
        return str(int(num1) * int(num2))
    
    mid1 = len(num1) // 2
    mid2 = len(num2) // 2

    # 将num1分成两部分
    a = num1[:mid1]
    b = num1[mid1:]
    # 将num2分成两部分
    c = num2[:mid2]
    d = num2[mid2:]

    m = len(b)      # m次幂
    n = len(d)      # n次幂

    # 分治计算，分别补上幂次
    x1 = big_int_mul(a, c) + '0' * (m + n)
    x2 = big_int_mul(b, c) + '0' * n
    x3 = big_int_mul(a, d) + '0' * m
    x4 = big_int_mul(b, d)

    # 将计算结果根据最长的补零，方便之后直接相加
    max_len = max(len(x1), len(x2), len(x3), len(x4))
    x1 = '0' * (max_len - len(x1)) + x1
    x2 = '0' * (max_len - len(x2)) + x2
    x3 = '0' * (max_len - len(x3)) + x3
    x4 = '0' * (max_len - len(x4)) + x4

    # 计算x1 + x2 + x3 + x4的值，也就是原问题的解
    result = ""
    carry = 0           # 保存进位
    for i in range(max_len - 1, -1, -1):
        s = int(x1[i]) + int(x2[i]) + int(x3[i]) + int(x4[i]) + carry
        result = str(s % 10) + result
        carry = s // 10
    # 判断是否存在进位
    if carry > 0:
        result = str(carry) + result
    
    # 去除结果前面多余的0
    i = 0
    while i < len(result) and result[i] == '0':
        i += 1
    return result[i:]

def main():
    num1 = "93281"
    num2 = "2034"
    print(big_int_mul(num1, num2))

if __name__ == "__main__":
    main()