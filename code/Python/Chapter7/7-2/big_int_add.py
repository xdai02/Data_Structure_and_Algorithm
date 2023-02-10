def big_int_add(num1, num2):
    # pad the shorter number with leading zeros
    if len(num1) > len(num2):
        num2 = num2.zfill(len(num1))
    else:
        num1 = num1.zfill(len(num2))

    result = ""
    carry = 0
    for i in range(len(num1) - 1, -1, -1):
        digit_sum = int(num1[i]) + int(num2[i]) + carry
        carry = digit_sum // 10
        digit = digit_sum % 10
        result = str(digit) + result
    
    if carry > 0:
        result = str(carry) + result
    return result

print(big_int_add("426709752318", "95481253129"))