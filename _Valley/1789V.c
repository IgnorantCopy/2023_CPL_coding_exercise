//
// Created by Ignorant on 2023/10/28.
//


#include <stdio.h>

int square[100][100] = {0};
int vectors1[12][2] = {
        {-2, 0},
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0,  -2},
        {0,  -1},
        {0,  1},
        {0,  2},
        {1,  -1},
        {1,  0},
        {1,  1},
        {2,  0}
};
int vectors2[24][2] = {
        {-2, -2},
        {-2, -1},
        {-2, 0},
        {-2, 1},
        {-2, 2},
        {-1, -2},
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {-1, 2},
        {0,  -2},
        {0,  -1},
        {0,  1},
        {0,  2},
        {1,  -2},
        {1,  -1},
        {1,  0},
        {1,  1},
        {1,  2},
        {2,  -2},
        {2,  -1},
        {2,  0},
        {2,  1},
        {2,  2}
};

int torch[25][2] = {0};
int stone[5][2] = {0};

int main() {
    int n = 0;
    int m = 0;
    int k = 0;
    int count = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &torch[i][0], &torch[i][1]);
        square[torch[i][0] - 1][torch[i][1] - 1] = 1;
        for (int j = 0; j < 12; j++) {
            int x = torch[i][0] - 1 + vectors1[j][0];
            int y = torch[i][1] - 1 + vectors1[j][1];
            if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1) {
                square[x][y] = 1;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &stone[i][0], &stone[i][1]);
        square[stone[i][0] - 1][stone[i][1] - 1] = 1;
        for (int j = 0; j < 24; j++) {
            int x = stone[i][0] - 1 + vectors2[j][0];
            int y = stone[i][1] - 1 + vectors2[j][1];
            if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1) {
                square[x][y] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (square[i][j] == 0) {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
