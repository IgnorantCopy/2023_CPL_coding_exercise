//
// Created by Ignorant on 2023/10/27.
//

#include <stdio.h>
int square[999][999] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    square[0][n / 2] = 1;
    int x = n / 2;
    int y = 0;
    for (int i = 2; i <= n * n; i++) {
        x = (x + 1 > n - 1) ? 0 : x + 1;
        y = (y - 1 < 0) ? n - 1 : y - 1;
        if (square[y][x] != 0) {
            x = (x == 0) ? n - 1 : x - 1;
            y = (y == n - 1) ? 1 : y + 2;
        }
        square[y][x] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", square[i][j], "\n"[j != n - 1]);
        }
    }
    return 0;
}
