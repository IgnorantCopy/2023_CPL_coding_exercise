//
// Created by Ignorant on 2023/10/12.
//


#include <stdio.h>
#define NUM 1000000007

int main() {
    long n = 0;
    scanf("%ld", &n);
    long long int result = 0;
    long long int temp = 1;
    for (int i = 1; i <= n; i++) {
        temp = (i % NUM) * (temp % NUM);
        result += temp % NUM;
    }
    printf("%lld", result % NUM);
    return 0;
}
