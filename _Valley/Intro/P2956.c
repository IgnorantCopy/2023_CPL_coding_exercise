//
// Created by Ignorant on 2023/11/7.
//


#include <stdio.h>

int square[240][240] = {0};

int main() {
    int x = 0;
    int y = 0;
    int n = 0;
    scanf("%d%d%d", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = y1 - 1; j < y2; j++) {
            for (int k = x1 - 1; k < x2; k++) {
                square[j][k] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (square[i][j] == 1) {
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
