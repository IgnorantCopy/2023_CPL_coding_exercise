//
// Created by Ignorant on 2023/10/27.
//


#include <stdio.h>
#include <string.h>

int main() {
    int m = 0;
    char n[1001] = {0};
    char result[6000] = {0};
    scanf("%d%s", &m, n);
    int len = strlen(n);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (n[i] != '0') {
            result[index++] = n[i];
            result[index++] = '*';
            result[index++] = m + 48;
            result[index++] = '^';
            result[index++] = len - 1 - i + 48;
            if (i != len - 1) {
                result[index++] = '+';
            }
        }
    }
    if (n[len - 1] == '0') {
        result[--index] = 0;
    }
    printf("%s", result);
    return 0;
}
