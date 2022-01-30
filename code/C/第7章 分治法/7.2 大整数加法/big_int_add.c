#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

void reverse(char *str) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    
    int i = 0;
    int j = len - 1;
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/**
 * @brief   大整数加法
 * @param   num1: 大整数1
 * @param   num2: 大整数2
 * @retval  相加结果
 */
char* bigIntAdd(char *num1, char *num2) {
    // 计算两个数中较长的整数位数
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = max(len1, len2);
    
    // 给结果字符串分配空间，大小为较长数的长度 + 2
    // 一个保存可能产生的进位，一位保存字符串结束符\0
    char *result = (char *)malloc(sizeof(char) * (maxLen + 2));
    if(!result) {
        return NULL;
    }
    memset(result, '0', sizeof(char) * (maxLen + 1));

    // 其中一个数为0，直接返回另一个数
    if(strcmp(num1, "0") == 0) {
        strcpy(result, num2);
        return result;
    } else if(strcmp(num2, "0") == 0) {
        strcpy(result, num1);
        return result;
    }

    // 将数字倒着保存到int数组中
    int n1[maxLen];
    int n2[maxLen];
    memset(n1, 0, sizeof(int) * maxLen);
    memset(n2, 0, sizeof(int) * maxLen);
    for(int i = 0; i < len1; i++) {
        n1[i] = num1[len1-i-1] - '0';
    }
    for(int i = 0; i < len2; i++) {
        n2[i] = num2[len2-i-1] - '0';
    }

    // 从左往右逐位相加
    for(int i = 0; i < maxLen; i++) {
        int s = n1[i] + n2[i] + (result[i] - '0');
        // 产生进位
        if(s >= 10) {
            result[i+1] = s / 10 + '0';
            s %= 10;
        }
        result[i] = s + '0';
    }
    result[maxLen+1] = '\0';

    // 逆序结果
    reverse(result);

    // 去除结果前面多余的0
    int i = 0;
    int j = 0;
    while(result[i] == '0') {
        i++;
    }
    while(result[i] != '\0') {
        result[j++] = result[i++];
    }
    result[j] = '\0';
    return result;
}

int main() {
    char num1[] = "426709752318";
    char num2[] = "95481253129";
    char *result = bigIntAdd(num1, num2);
    if(result) {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}