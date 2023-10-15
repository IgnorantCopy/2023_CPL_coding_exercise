//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>

int main() {
    int t = 0;
    int n = 0;
    scanf("%d", &t);
    int isRight[t];
    long long int max;
    for (int i = 0; i < t; i++) {
        max = -1000000000;
        scanf("%d", &n);
        long long int numbers[n];
        for (int j = 0; j < n; j++) {
            scanf("%lld", &numbers[j]);
            max = max > numbers[j] ? max : numbers[j];
        }
        if (max == numbers[n - 1]) {
            isRight[i] = 1;
        } else {
            isRight[i] = 0;
        }
    }
    for (int i = 0; i < t; i++) {
        if (isRight[i] == 1) {
            printf("Yes");
        } else {
            printf("No");
        }
        if (i < t - 1) {
            printf("\n");
        }
    }
    return 0;
}
