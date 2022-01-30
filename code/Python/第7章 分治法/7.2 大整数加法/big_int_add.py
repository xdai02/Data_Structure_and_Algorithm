def big_int_add(num1, num2):
    """
    大整数相加
    Args:
        num1 (str): 大整数1
        num2 (str): 大整数2
    Returns:
        [str]: 相加结果
    """
    # 其中一个数为0，直接返回另一个数
    if num1 == "0":
        return num2
    elif num2 == "0":
        return num1
    
    # 计算两个数中较长的整数位数
    max_len = max(len(num1), len(num2))
    # 让位数较短的整数前面补0对齐
    num1 = '0' * (max_len - len(num1)) + num1
    num2 = '0' * (max_len - len(num2)) + num2

    result = ""         # 结果
    carry = 0           # 保存进位
    # 从右往左逐位相加
    for i in range(max_len - 1, -1, -1):
        s = int(num1[i]) + int(num2[i]) + carry
        result = str(s % 10) + result
        carry = s // 10
    
    # 判断最高位是否有进位
    if carry > 0:
        result = str(carry) + result
    
    # 去除结果前面多余的0
    i = 0
    while result[i] == '0':
        i += 1
    return result[i:]

def main():
    print(big_int_add("426709752318", "95481253129"))

if __name__ == "__main__":
    main()