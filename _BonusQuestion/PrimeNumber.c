//
// Created by Ignorant on 2023/9/27.
//


#include <stdio.h>
#define N 50000001

int flag[N] = {0};

int main() {
    long int n = 0;
    long int sum = 0;
    scanf("%ld", &n);
    for (int i = 2; i < n + 1; i++) {
        if (flag[i] == 0) {
            sum++;
        }
        for (int j = 2, m = j * i; (flag[j] == 1) && (m < n + 1); j++) {
            flag[m] = 1;
        }
    }
    printf("%ld", sum);
    return 0;
}
