#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *big_int_add(const char *num1, const char *num2) {
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int len = num1_len > num2_len ? num1_len : num2_len;

    char *number1 = (char *)malloc(sizeof(char) * (len + 1));
    char *number2 = (char *)malloc(sizeof(char) * (len + 1));

    // copy num1 to number1, num2 to number2, and pad the shorter number with leading zeros
    if (num1_len > num2_len) {
        strcpy(number1, num1);
        for (int i = 0; i < num1_len - num2_len; i++) {
            number2[i] = '0';
        }
        strcpy(number2 + num1_len - num2_len, num2);
    } else {
        strcpy(number2, num2);
        for (int i = 0; i < num2_len - num1_len; i++) {
            number1[i] = '0';
        }
        strcpy(number1 + num2_len - num1_len, num1);
    }

    char *result = (char *)calloc(len + 2, sizeof(char));
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int digit_sum = number1[i] - '0' + number2[i] - '0' + carry;
        carry = digit_sum / 10;
        int digit = digit_sum % 10;
        result[i + 1] = digit + '0';
    }

    if (carry > 0) {
        result[0] = carry + '0';
    } else {
        result++;
    }

    free(number1);
    free(number2);

    return result;
}

int main() {
    char *result = big_int_add("426709752318", "95481253129");
    printf("%s\n", result);
    free(result);
    return 0;
}
