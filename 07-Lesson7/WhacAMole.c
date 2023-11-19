//
// Created by Ignorant on 2023/11/18.
//


#include <stdio.h>
#include <math.h>
#include <limits.h>

int square[700][700] = {0};
int results[360000][2] = {0};

int main() {
    int n = 0;
    int m = 0;
    int d = 0;
    int maxValue = INT_MIN;
    int ansN = 0;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 49; i < n + 49; i++) {
        for (int j = 49; j < m + 49; j++) {
            scanf("%d", &square[i][j]);
        }
    }
    int value = 0;
    int i = 49;
    int j = 49;
    int count = 1;
    char direction = 'r';
    for (int k = i; k <= i + d; k++) {
        for (int l = j; l <= j + d; l++) {
            if (abs(k - i) + abs(l - j) <= d) {
                value += square[k][l];
            }
        }
    }
    while (count++ != n * m + 1) {
        if (value > maxValue) {
            maxValue = value;
            ansN = 1;
            results[ansN - 1][0] = i - 48;
            results[ansN - 1][1] = j - 48;
        } else if (value == maxValue) {
            ansN++;
            results[ansN - 1][0] = i - 48;
            results[ansN - 1][1] = j - 48;
        }
        switch (direction) {
            case 'r':
                j++;
                int k = i - d;
                for (int l = j - 1; l > j - 1 - d; l--) {
                    value -= square[k++][l];
                }
                for (int l = j - 1 - d; l <= j - 1; l++) {
                    value -= square[k++][l];
                }
                k = i - d;
                for (int l = j; l < j + d; l++) {
                    value += square[k++][l];
                }
                for (int l = j + d; l >= j; l--) {
                    value += square[k++][l];
                }
                if (j == m + 48) {
                    direction = 'd';
                }
                break;
            case 'd':
                i++;
                int l = j - d;
                for (int index = i - 1; index > i - 1 - d; index--) {
                    value -= square[index][l++];
                }
                for (int index = i - 1 - d; index <= i - 1; index++) {
                    value -= square[index][l++];
                }
                l = j - d;
                for (int index = i; index < i + d; index++) {
                    value += square[index][l++];
                }
                for (int index = i + d; index >= i; index--) {
                    value += square[index][l++];
                }
                if (j == 49) {
                    direction = 'r';
                } else if (j == m + 48) {
                    direction = 'l';
                }
                break;
            case 'l':
                j--;
                k = i - d;
                for (int index = j + 1; index < j + 1 + d; index++) {
                    value -= square[k++][index];
                }
                for (int index = j + 1 + d; index >= j + 1; index--) {
                    value -= square[k++][index];
                }
                k = i - d;
                for (int index = j; index > j - d; index--) {
                    value += square[k++][index];
                }
                for (int index = j - d; index <= j; index++) {
                    value += square[k++][index];
                }
                if (j == 49) {
                    direction = 'd';
                }
                break;
        }
    }
    printf("%d %d\n", maxValue, ansN);
    for (int k = 0; k < ansN; k++) {
        printf("%d %d\n", results[k][0], results[k][1]);
    }
    return 0;
}
