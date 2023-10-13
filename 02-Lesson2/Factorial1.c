//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>

int main() {
    const int num = 10007;
    int n = 0;
    scanf("%d", &n);
    int result = 0;
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        temp = (i % num) * (temp % num);
        result += temp % num;
    }
    printf("%d", result % num);
    return 0;
}
