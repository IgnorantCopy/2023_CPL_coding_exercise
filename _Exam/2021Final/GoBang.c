//
// Created by Ignorant on 2023/12/31.
//


#include <stdio.h>

#define LEN 20

char board[LEN][LEN + 1] = {0};

int vectors[8][2] = {
        {-1, -1},
        {1,  1},
        {0,  -1},
        {0,  1},
        {1,  -1},
        {-1, 1},
        {-1, 0},
        {1,  0},
};

int IsFinish();

int IsLinear(int x, int y, int isBlack);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < LEN; j++) {
            scanf("%s", board[j]);
        }
        int result = IsFinish();
        if (result == 1) {
            printf("Lose\n");
        } else if (result == -1) {
            printf("Win\n");
        } else {
            printf("Not Sure\n");
        }
    }
    return 0;
}

int IsFinish() {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (board[i][j] == '_' && IsLinear(j, i, 0)) {
                return 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (board[i][j] == '_' && IsLinear(j, i, 1)) {
                count++;
                if (count == 2) {
                    return -1;
                }
            }
        }
    }
    return 0;
}

int IsLinear(int x, int y, int isBlack) {
    char key = isBlack ? '#' : '*';
    for (int i = 0; i < 8; i += 2) {
        int newX = x + vectors[i][0];
        int newY = y + vectors[i][1];
        int count = 0;
        while (newX >= 0 && newX < LEN && newY >= 0 && newY < LEN && key == board[newY][newX]) {
            count++;
            if (count == 4) {
                return 1;
            }
            newX += vectors[i][0];
            newY += vectors[i][1];
        }
        newX = x + vectors[i + 1][0];
        newY = y + vectors[i + 1][1];
        while (newX >= 0 && newX < LEN && newY >= 0 && newY < LEN && key == board[newY][newX]) {
            count++;
            if (count == 4) {
                return 1;
            }
            newX += vectors[i + 1][0];
            newY += vectors[i + 1][1];
        }
    }
    return 0;
}
