//
// Created by Ignorant on 2023/10/27.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int t = 0;
    char num[10] = {0};
    int sum = 0;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        num[i] = t + 48;
        sum += atoi(num);
    }
    printf("%d", sum);
    return 0;
}
