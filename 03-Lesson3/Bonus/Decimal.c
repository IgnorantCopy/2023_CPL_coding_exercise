//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main() {
    int len = 0;
    int n = 0;
    int num = 0;
    long long int result = 0;
    scanf("%d%d", &len, &n);
    char number[len + 1];
    scanf("%s", number);
    for (int i = 0; i < len; i++) {
        switch (number[i]) {
            case 'A':
                num = 10;
                break;
            case 'B':
                num = 11;
                break;
            case 'C':
                num = 12;
                break;
            case 'D':
                num = 13;
                break;
            case 'E':
                num = 14;
                break;
            case 'F':
                num = 15;
                break;
            default:
                if (isalpha(number[i])) {
                    printf("Error");
                    goto flag;
                } else {
                    num = number[i] - 48;
                }
        }
        if (num >= n) {
            printf("Error");
            goto flag;
        }
        result += num * pow(n, len - i - 1);
    }
    printf("%lld", result);
    flag:
    return 0;
}
