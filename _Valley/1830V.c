//
// Created by Ignorant on 2023/10/29.
//


#include <stdio.h>

int square[100][100][2] = {0};

int main() {
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < x; i++) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = x1 - 1; j < x2; j++) {
            for (int k = y1 - 1; k < y2; k++) {
                square[k][j][0]++;
                square[k][j][1] = i + 1;
            }
        }
    }
    for (int i = 0; i < y; i++) {
        int newX = 0;
        int newY = 0;
        scanf("%d%d", &newX, &newY);
        if (square[newY - 1][newX - 1][0]) {
            printf("Y %d %d\n", square[newY - 1][newX - 1][0], square[newY - 1][newX - 1][1]);
        } else {
            printf("N\n");
        }
    }
    return 0;
}
