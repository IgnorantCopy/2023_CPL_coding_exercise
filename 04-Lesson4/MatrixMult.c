//
// Created by Ignorant on 2023/10/21.
//


#include <stdio.h>

int arrA[100][100] = {0};
int arrB[100][100] = {0};
int arrC[100][100] = {0};

int main() {
    int m = 0;
    int n = 0;
    int p = 0;
    scanf("%d%d%d", &m, &n, &p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arrA[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &arrB[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d", arrC[i][j]);
            if (j != p - 1) {
                printf(" ");
            }
        }
        if (i != m - 1) {
            printf("\n");
        }
    }
    return 0;
}
