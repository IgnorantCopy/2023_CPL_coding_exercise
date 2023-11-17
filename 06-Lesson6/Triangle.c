//
// Created by Ignorant on 2023/11/12.
//


#include <stdio.h>
#include <math.h>

char board[1025][2049] = {0};

void Paint(int x, int y, int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int scale = 4 * pow(2, n - 1);
    for (int i = 0; i < scale / 2 + 1; i++) {
        for (int j = 0; j < scale + 1; j++) {
            if (j == scale) {
                board[i][j] = 0;
            } else {
                board[i][j] = ' ';
            }
        }
    }
    Paint(0, 0, n);
    for (int i = 0; i < scale / 2; i++) {
        printf("%s\n", board[i]);
    }
    return 0;
}

void Paint(int x, int y, int n) {
    if (n == 1) {
        board[y][x + 1] = '/';
        board[y][x + 2] = '\\';
        board[y + 1][x] = '/';
        board[y + 1][x + 1] = '_';
        board[y + 1][x + 2] = '_';
        board[y + 1][x + 3] = '\\';
        return;
    }
    Paint(x + 2 * pow(2, n - 2), y, n - 1);
    Paint(x, y + 2 * pow(2, n - 2), n - 1);
    Paint(x + 2 * pow(2, n - 1), y + 2 * pow(2, n - 2), n - 1);
}
