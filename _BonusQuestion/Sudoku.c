//
// Created by Ignorant on 2024/1/3.
//


#include <stdio.h>
#define LEN 9

int board[LEN][LEN][LEN + 1] = {0};

void Solve();

int IsSolved();

int GetPossibleNumber(int *arr, int x, int y);

int SearchBlock(int x, int y, int target);

int SearchColumn(int col, int target);

int SearchRow(int row, int target);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < LEN; j++) {
            for (int k = 0; k < LEN; k++) {
                scanf("%d", &board[j][k][0]);
            }
        }
        while (!IsSolved()) {
            Solve();
        }
        for (int j = 0; j < LEN; j++) {
            for (int k = 0; k < LEN; k++) {
                printf("%d", board[j][k][0]);
            }
            printf("\n");
        }
        
    }
    return 0;
}

void Solve() {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (board[i][j][0] == 0 && GetPossibleNumber(board[i][j], j, i) == 1) {
                board[i][j][0] = board[i][j][1];
            }
        }
    }
}

int IsSolved() {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (board[i][j][0] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int GetPossibleNumber(int *arr, int x, int y) {
    int count = 0;
    for (int i = 1; i < 10; i++) {
        if (SearchBlock(x, y, i) && SearchRow(y, i) && SearchColumn(x, i)) {
            arr[++count] = i;
        }
    }
    return count;
}

int SearchBlock(int x, int y, int target) {
    for (int i = y / 3 * 3; i < (y / 3 + 1) * 3; i++) {
        for (int j = x / 3 * 3; j < (x / 3 + 1) * 3; j++) {
            if (target == board[i][j][0]) {
                return 0;
            }
        }
    }
    return 1;
}

int SearchColumn(int col, int target) {
    for (int i = 0; i < LEN; i++) {
        if (target == board[i][col][0]) {
            return 0;
        }
    }
    return 1;
}

int SearchRow(int row, int target) {
    for (int i = 0; i < LEN; i++) {
        if (target == board[row][i][0]) {
            return 0;
        }
    }
    return 1;
}
