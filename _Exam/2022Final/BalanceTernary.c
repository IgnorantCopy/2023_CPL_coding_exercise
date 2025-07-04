//
// Created by Ignorant on 2023/12/27.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

char numbers[10001] = {0};

int D();

int T();

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char key[5] = {0};
        scanf("%s", key);
        switch (key[0]) {
            case 'd':
                D();
                break;
            case 't':
                T();
                break;
            default:
                break;
        }
    }
    return 0;
}

int D() {
    scanf("%s", numbers);
    char result[10001] = {0};
    for (int i = 0; i < strlen(numbers); i++) {
        if (isalpha(numbers[i]) || (i != 0 && numbers[i] == '-')) {
            printf("Radix Error\n");
            return 0;
        }
    }
    if (atoi(numbers) == 0) {
        result[0] = '0';
    } else {
        int num = abs(atoi(numbers));
        for (int i = 0; num != 0; i++) {
            result[i] += num % 3 + 48;
            num /= 3;
            if (result[i] == '2') {
                result[i] = 'Z';
                result[i + 1] += num != 0 ? 1 : 49;
            } else if (result[i] == '3') {
                result[i] = '0';
                result[i + 1] += num != 0 ? 1 : 49;
            }
        }
    }
    printf("%s ", numbers);
    for (int i = strlen(result) - 1; i >= 0; i--) {
        if (atoi(numbers) < 0) {
            if (result[i] == '1') {
                result[i] = 'Z';
            } else if (result[i] == 'Z') {
                result[i] = '1';
            }
        }
        printf("%c", result[i]);
    }
    printf("\n");
    return 1;
}

int T() {
    int result = 0;
    scanf("%s", numbers);
    size_t length = strlen(numbers);
    for (int i = 0; i < length; i++) {
        if (length == 1 && numbers[0] == '0') {
            break;
        } else if (numbers[0] != '1' && numbers[0] != 'Z') {
            printf("Radix Error\n");
            return 0;
        } else if (!isalpha(numbers[i])) {
            if (numbers[i] != '0' && numbers[i] != '1') {
                printf("Radix Error\n");
                return 0;
            } else {
                result += (numbers[i] - 48) * pow(3, length - i - 1);
            }
        } else {
            if (numbers[i] != 'Z') {
                printf("Radix Error\n");
                return 0;
            } else {
                result -= pow(3, length - i - 1);
            }
        }
    }
    printf("%d %s\n", result, numbers);
    return 1;
}
