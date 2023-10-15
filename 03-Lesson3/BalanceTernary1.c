//
// Created by Ignorant on 2023/10/14.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    int n = 0;
    long long int result;
    int isError;
    char numbers[10001][16] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        result = 0;
        isError = 0;
        for (int j = 0; j < strlen(numbers[i]); j++) {
            if (strlen(numbers[i]) == 1 && numbers[i][0] == '0') {
                break;
            } else if (numbers[i][0] != '1' && numbers[i][0] != 'Z') {
                printf("Radix Error");
                isError = 1;
                break;
            } else if (!isalpha(numbers[i][j])) {
                if (numbers[i][j] != '0' && numbers[i][j] != '1') {
                    printf("Radix Error");
                    isError = 1;
                    break;
                } else {
                    result += ((int)numbers[i][j] - 48) * pow(3, strlen(numbers[i]) - j - 1);
                }
            } else {
                if (numbers[i][j] != 'Z') {
                    printf("Radix Error");
                    isError = 1;
                    break;
                } else {
                    result -= pow(3, strlen(numbers[i]) - j - 1);
                }
            }
        }
        if (!isError) {
            printf("%lld", result);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
    return 0;
}
