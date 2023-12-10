//
// Created by Ignorant on 2023/12/9.
//

#include <stdio.h>

char board[3001][3001] = {0};

int Solve(int row, int col);

int main() {
    int row = 0;
    int col = 0;
    scanf("%d%d", &row, &col);
    for (int i = 0; i < row; i++) {
        scanf("%s", board[i]);
    }
    printf("%d", Solve(row, col));
    return 0;
}

int Solve(int row, int col) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char key = board[i][j];
            int isDangerU = 1;
            int isDangerD = 1;
            int isDangerL = 1;
            int isDangerR = 1;
            if (key != '.') {
                // U
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j] != '.') {
                        isDangerU = 0;
                        break;
                    }
                }
                // L
                for (int k = j - 1; k >= 0; k--) {
                    if (board[i][k] != '.') {
                        isDangerL = 0;
                        break;
                    }
                }
                // R
                for (int k = j + 1; k < col; k++) {
                    if (board[i][k] != '.') {
                        isDangerR = 0;
                        break;
                    }
                }
                // D
                for (int k = i + 1; k < row; k++) {
                    if (board[k][j] != '.') {
                        isDangerD = 0;
                        break;
                    }
                }
                if (isDangerU && isDangerD && isDangerR && isDangerL) {
                    return -1;
                } else if ((key == 'U' && isDangerU) || (key == 'D' && isDangerD) || (key == 'L' && isDangerL) ||
                           (key == 'R' && isDangerR)) {
                    count++;
                }
            }
        }
    }
    return count;
}
