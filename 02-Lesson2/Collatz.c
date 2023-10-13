//
// Created by Ignorant on 2023/10/9.
//


#include <stdio.h>

int main() {
    int n = 0;
    int step = 0;
    scanf("%d", &n);
    int max = n;
    while (n != 1) {
        step++;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
            max = max > n ? max : n;
        }
    }
    printf("%d %d", step, max);
    return 0;
}
