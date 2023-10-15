//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>

char string[100001];
int main() {
    int n = 0;
    scanf("%d %s", &n, string);
    char select[10][10][3] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            select[i][j][0] = i + 48;
            select[i][j][1] = j + 48;
        }
    }
    for (int i = 0; i < n; i++) {
        if (string[i] == '?' && string[n - i - 1] != '?') {
            string[i] = string[n - i - 1];
        }
    }
    int x = 0;
    int y = 0;
    int coordinate[1000001][2];
    for (int i = 0; i < n / 2; i++) {
        if (string[i] != '?') {
            putchar(string[i]);
        } else {
            printf("%.2s", select[x][y]);
            coordinate[i][0] = x;
            coordinate[i][1] = y;
            coordinate[n - i - 1][0] = y;
            coordinate[n - i - 1][1] = x;
            if (y < 9) {
                y++;
            } else {
                x++;
                y = 0;
            }
        }
    }
    for (int i = n / 2; i < n; i++) {
        if (string[i] != '?') {
            putchar(string[i]);
        } else {
            printf("%.2s", select[coordinate[i][0]][coordinate[i][1]]);
        }
    }
    return 0;
}
