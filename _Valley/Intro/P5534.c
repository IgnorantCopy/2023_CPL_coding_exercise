//
// Created by Ignorant on 2023/12/9.
//


#include <stdio.h>

int main() {
    int a1 = 0;
    int a2 = 0;
    int n = 0;
    scanf("%d%d%d", &a1, &a2, &n);
    int d = a2 - a1;
    long long int sum = 0;
    long long int an = a1;
    for (int i = 0; i < n; i++) {
        sum += an;
        an += d;
    }
    printf("%lld", sum);
    return 0;
}
