#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

/**
 * @brief  拼接两个字符串
 * @note   申请新的字符串空间
 * @param  s1: 字符串1
 * @param  s2: 字符串2
 * @retval 拼接后的字符串
 */
char* concat(char *s1, char *s2) {
    char *str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
    if(!str) {
        return NULL;
    }
    strcpy(str, s1);
    strcat(str, s2);
    free(s1);
    return str;
}

/**
 * @brief  在数字字符串前补0
 * @param  num: 数字字符串
 * @param  n: 补0的个数
 * @retval 补0后的数字字符串
 */
char *addLeadingZeros(char *num, int n) {
    char *str = (char *)malloc(sizeof(char) * (strlen(num) + n + 1));
    if(!str) {
        return NULL;
    }
    strcpy(str, "\0");
    for(int i = 0; i < n; i++) {
        strcat(str, "0");
    }
    strcat(str, num);
    free(num);
    return str;
}

/**
 * @brief   大整数乘法
 * @param   num1: 大整数1
 * @param   num2: 大整数2
 * @retval  相乘结果
 */
char* bigIntMul(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 + len2;
    char *result = (char *)malloc(sizeof(char) * (maxLen + 1));
    if(!result) {
        return NULL;
    }

    // 有一个为空，结果为0
    if(len1 == 0 || len2 == 0) {
        strcpy(result, "0");
        return result;
    }
    // 终止条件
    else if(len1 == 1 && len2 == 1) {
        return itoa(atoi(num1) * atoi(num2), result, 10);
    }

    int mid1 = len1 / 2;
    int mid2 = len2 / 2;
    
    char a[maxLen], b[maxLen], c[maxLen], d[maxLen];
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    memset(c, '\0', sizeof(c));
    memset(d, '\0', sizeof(d));
    
    // 将num1分成两部分
    strncpy(a, num1, mid1);
    strcpy(b, num1 + mid1);
    // 将num2分成两部分
    strncpy(c, num2, mid2);
    strcpy(d, num2 + mid2);

    int m = strlen(b);		// m次幂
    int n = strlen(d);		// n次幂

    char *zeros = (char *)malloc(sizeof(char) * maxLen);
    if(!zeros) {
        return NULL;
    }

    // 分治计算，分别补上幂次
    char *x1, *x2, *x3, *x4;
    memset(zeros, '\0', sizeof(char) * maxLen);
    for(int i = 0; i < m + n; i++) {
        strcat(zeros, "0");
    }
    x1 = concat(bigIntMul(a, c), zeros);
    memset(zeros, '\0', sizeof(char) * maxLen);
    for(int i = 0; i < n; i++) {
        strcat(zeros, "0");
    }
    x2 = concat(bigIntMul(b, c), zeros);
    memset(zeros, '\0', sizeof(char) * maxLen);
    for(int i = 0; i < m; i++) {
        strcat(zeros, "0");
    }
    x3 = concat(bigIntMul(a, d), zeros);
    x4 = bigIntMul(b, d);
    free(zeros);

    // 将计算结果根据最长的补零，方便之后直接相加
    maxLen = max(max(strlen(x1), strlen(x2)), max(strlen(x3), strlen(x4)));
    x1 = addLeadingZeros(x1, maxLen - strlen(x1));
    x2 = addLeadingZeros(x2, maxLen - strlen(x2));
    x3 = addLeadingZeros(x3, maxLen - strlen(x3));
    x4 = addLeadingZeros(x4, maxLen - strlen(x4));

    // 计算x1 + x2 + x3 + x4的值，也就是原问题的解
    char digit[2];
    char *temp;
    int carry = 0;		// 保存进位
    for(int i = maxLen - 1; i >= 0; i--) {
        int s = (x1[i] - '0') + (x2[i] - '0') + (x3[i] - '0') + (x4[i] - '0') + carry;
        temp = concat(itoa(s % 10, digit, 10), result);
        strcpy(result, temp);
        free(temp);
        carry = s / 10;
    }
    // 判断是否存在进位
    if(carry > 0) {
        temp = concat(itoa(carry, digit, 10), result);
        strcpy(result, temp);
        free(temp);
    }
    free(x1);
    free(x2);
    free(x3);
    free(x4);

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
    char num1[] = "93281";
    char num2[] = "2034";
    char *result = bigIntMul(num1, num2);
    if(result) {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}