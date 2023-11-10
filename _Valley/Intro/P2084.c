//
// Created by Ignorant on 2023/10/27.
//


#include <stdio.h>
#include <string.h>

int main() {
    int m = 0;
    char n[1001] = {0};
    scanf("%d%s", &m, n);
    int len = strlen(n);
    for (int i = 0; i < len; i++) {
        if (n[i] != '0') {
            if (i != 0) {
                printf("+");
            }
            printf("%c*%d^%d", n[i], m, len - 1 - i);
        }
    }
    return 0;
}
