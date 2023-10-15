//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>

int main() {
    int bit[2000] = {0};
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (bit[j - 1] == 0) {
                bit[j - 1] = 1;
            } else {
                bit[j - 1] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (bit[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}
