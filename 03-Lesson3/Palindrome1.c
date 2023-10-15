//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>

int main() {
    int n = 0;
    char str[2000] = {0};
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &str[i]);
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') {
            str[i] = str[n - 1 - i];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    return 0;
}
