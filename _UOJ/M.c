//
// Created by Ignorant on 2023/12/2.
//

#include <stdio.h>
int matrix[120][120] = {0};
int sums[120][120] = {0};

int getSum(int x1, int y1, int x2, int y2);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (j == 0) {
                sums[i][j] = matrix[i][j];
            } else {
                sums[i][j] = matrix[i][j] + sums[i][j - 1];
            }

        }
        for (int j = 0; j < n; j++) {
            if (i != 0) {
                sums[i][j] += sums[i - 1][j];
            }
        }
    }
    int max = sums[0][0];
    for (int y1 = 0, x1 = 0; y1 != n - 1 || x1 != n - 1;) {
        for (int y2 = y1, x2 = x1; y2 != n - 1 || x2 != n - 1;) {
            max = max > getSum(x1, y1, x2, y2) ? max : getSum(x1, y1, x2, y2);
            if (x2 == n - 1) {
                x2 = x1;
                y2++;
            } else {
                x2++;
            }
        }
        if (x1 == n - 1) {
            x1 = 0;
            y1++;
        } else {
            x1++;
        }
    }
    printf("%d", max);
    return 0;
}

int getSum(int x1, int y1, int x2, int y2) {
    if (x1 == 0 && y1 == 0) {
        return sums[y2][x2];
    } else if (x1 == 0) {
        return sums[y2][x2] - sums[y1 - 1][x2];
    } else if (y1 == 0) {
        return sums[y2][x2] - sums[y2][x1 - 1];
    }
    return sums[y2][x2] - sums[y1 - 1][x2] - sums[y2][x1 - 1] + sums[y1 - 1][x1 - 1];
}
