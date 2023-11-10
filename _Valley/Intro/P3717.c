//
// Created by Ignorant on 2023/11/7.
//


#include <stdio.h>
#include <math.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int square[100][100] = {0};

int main() {
    int n = 0;
    int m = 0;
    int r = 0;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        scanf("%d%d", &x, &y);
        for (int j = MAX(y - 1 - r, 0); j < MIN(y + r, n); j++) {
            for (int k = MAX(x - 1 - r, 0); k < MIN(x + r, n); k++) {
                double distance = sqrt(pow(abs(k - x + 1), 2) + pow(abs(j - y + 1), 2));
                if (distance <= r) {
                    square[j][k] = 1;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (square[i][j] == 1) {
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
