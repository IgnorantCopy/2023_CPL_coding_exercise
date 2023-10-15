//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int isError;
    int num;
    char result[10001][100] = {0};
    char numbers[10001][16] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        isError = 0;
        num = 0;
        for (int j = 0; j < strlen(numbers[i]); j++) {
            if (isalpha(numbers[i][j])) {
                printf("Radix Error");
                isError = 1;
                break;
            }
        }
        if (!isError) {
            if (atoi(numbers[i]) == 0) {
                result[i][0] = '0';
            } else {
                num = abs(atoi(numbers[i]));
                for (int j = 0; num != 0; j++) {
                    result[i][j] += num % 3 + 48;
                    num /= 3;
                    if (result[i][j] == '0' || result[i][j] == '1') {
                        continue;
                    } else if (result[i][j] == '2') {
                        result[i][j] = 'Z';
                        if (num != 0) {
                            result[i][j + 1] += 1;
                        } else {
                            result[i][j + 1] += 49;
                        }
                    } else if (result[i][j] == '3') {
                        result[i][j] = '0';
                        if (num != 0) {
                            result[i][j + 1] += 1;
                        } else {
                            result[i][j + 1] += 49;
                        }
                    }
                }
            }
            if (atoi(numbers[i]) >= 0) {
                for (int j = strlen(result[i]) - 1; j >= 0 ; j--) {
                    printf("%c", result[i][j]);
                }
            } else {
                for (int j = strlen(result[i]) - 1; j >= 0 ; j--) {
                    if (result[i][j] == '1') {
                        result[i][j] = 'Z';
                    } else if (result[i][j] == 'Z') {
                        result[i][j] = '1';
                    }
                    printf("%c", result[i][j]);
                }
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
    return 0;
}
