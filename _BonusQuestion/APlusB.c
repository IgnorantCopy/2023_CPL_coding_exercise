//
// Created by Ignorant on 2023/10/15.
//

#include <stdio.h>
#include <string.h>
char numbers[1000][3][1002] = {0};
char out[1000][1003] = {0};

int main() {
    int line = 0;
    int index = -1;
    while ((scanf("%s", numbers[line][++index])) != EOF) {
        if (index == 1) {
            index = -1;
            line++;
        }
    }
    for (int i = 0; i < line; i++) {
        int len1 = strlen(numbers[i][0]);
        int len2 = strlen(numbers[i][1]);
        int j = len1 - 1;
        int k = len2 - 1;
        int bit = 0;
        int num1;
        int num2;
        while (1) {
            num1 = 0;
            num2 = 0;
            if (j >= 0) {
                num1 = numbers[i][0][j] - 48;
                j--;
            }
            if (k >= 0) {
                num2 = numbers[i][1][k] - 48;
                k--;
            }
            int num = num1 + num2 + out[i][bit];
            out[i][bit] = num % 10 + 48;
            if (j == -1 && k == -1) {
                if (num >= 10) {
                    out[i][bit + 1] = num / 10 + 48;
                }
                break;
            } else if (num >= 10) {
                out[i][bit + 1] = num / 10;
            }
            bit++;
        }
    }
    for (int i = 0; i < line; i++) {
        int j = strlen(out[i]) - 1;
        if (out[i][strlen(out[i]) - 1] == '0' && j != 0) {
            j--;
        }
        for (; j >= 0; j--) {
            printf("%c", out[i][j]);
        }
        if (i != line - 1) {
            printf("\n");
        }
    }
    return 0;
}
