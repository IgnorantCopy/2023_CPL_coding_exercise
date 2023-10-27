//
// Created by Ignorant on 2023/10/21.
//


#include <stdio.h>
#include <stdbool.h>

bool vis[52][52] = {0};
char arr[50][50] = {0};
char newArr[52][52] = {0};
int out[2500][2] = {0};
int vectors[4][2] = {
        {-1, 0},
        {0,  -1},
        {0,  1},
        {1,  0}
};

int main() {
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;
    int ans = 1;
    bool isEnd = true;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            newArr[i][j] = arr[i - 1][j - 1];
        }
    }
    int count;
    vis[x][y] = true;
    do {
        out[ans - 1][0] = x;
        out[ans - 1][1] = y;
        count = 0;
        for (int i = 0; i < 4; i++) {
            int newX = x + vectors[i][0];
            int newY = y + vectors[i][1];
            if (newArr[newX][newY] == '#' && vis[newX][newY] == false) {
                x = newX;
                y = newY;
                ans++;
                vis[newX][newY] = true;
                break;
            }
            count++;
        }
        if (count == 4) {
            isEnd = false;
        }
    } while (isEnd);
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++) {
        printf("%d %d", out[i][0], out[i][1]);
        if (i != ans - 1) {
            printf("\n");
        }
    }
    return 0;
}
