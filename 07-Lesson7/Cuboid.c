//
// Created by Ignorant on 2023/11/19.
//


#include <stdio.h>
#define LEN 82

char board[LEN][LEN] = {0};

void A0(int x, int y, int len);

void A1(int x, int y, int len);

void A2(int x, int y, int len);

void B0(int x, int y, int len);

void B2(int x, int y, int len);

void Cuboid(int a, int b, int c);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        scanf("%d%d%d", &a, &b, &c);
        Cuboid(a, b, c);
    }
    return 0;
}

void A0(int x, int y, int len) {
    for (int i = x; i < x + len; i += 2) {
        board[y][i] = '+';
        if (i != x + len - 1) {
            board[y][i + 1] = '-';
        }
    }
}

void A1(int x, int y, int len) {
    for (int i = x; i < x + len; i += 2) {
        board[y][i] = '|';
    }
}

void A2(int x, int y, int len) {
    for (int i = x; i < x + len; i += 2) {
        board[y][i] = '/';
    }
}

void B0(int x, int y, int len) {
    for (int i = y; i < y + len; i += 2) {
        board[i][x] = '+';
        if (i != y + len - 1) {
            board[i + 1][x] = '|';
        }
    }
}

void B2(int x, int y, int len) {
    for (int i = y; i < y + len; i += 2) {
        board[i][x] = '/';
    }
}

void Cuboid(int a, int b, int c) {
    int newA = 2 * a + 1;
    int newB = 2 * b + 1;
    int newC = 2 * c + 1;
    for (int i = 0; i < newC + newB; i++) {
        for (int j = 0; j < newA + newB; j++) {
            if (i != newC + newB - 1 && j != newA + newB - 1) {
                board[i][j] = ' ';
            } else {
                board[i][j] = 0;
            }
        }
    }
    for (int i = b; i > 0; i--) {
        A0(2 * i, 2 * (b - i), newA);
        B0(2 * i + newA - 1, 2 * (b - i), newC);
        A2(2 * i - 1, 2 * (b - i) + 1, newA);
        B2(2 * i + newA - 2, 2 * (b - i) + 1, newC);
    }
    for (int i = 0; i < c; i++) {
        A0(0, 2 * i + newB - 1, newA);
        A1(0, 2 * i + newB, newA);
    }
    A0(0, newC + newB - 2, newA);
    for (int i = 0; i < newB + newC - 1; i++) {
        printf("%s\n", board[i]);
    }
}
