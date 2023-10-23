//
// Created by Ignorant on 2023/10/21.
//


#include <stdio.h>

char arr[100][100] = {0};
char newArr[102][102] = {0};
int vectors[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0,  -1},
        {0,  1},
        {1,  -1},
        {1,  0},
        {1,  1}
};

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            newArr[i][j] = arr[i - 1][j - 1];
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            int count = 0;
            if (newArr[i][j] == 'o') {
                for (int k = 0; k < 8; k++) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    if (newArr[newI][newJ] == '*') {
                        count++;
                    }
                }
                newArr[i][j] = count + 48;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            printf("%c", newArr[i][j]);
        }
        if (i != n) {
            printf("\n");
        }
    }
    return 0;
}
