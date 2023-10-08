//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    if (num >= 65 && num <= 90) {
        printf("%d %c\n", num, num);
        printf("%d %c\n", num + 32, num + 32);
    }
    return 0;
}
