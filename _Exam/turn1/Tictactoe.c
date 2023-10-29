//
// Created by Ignorant on 2023/10/29.
//

#include <stdio.h>

int square[10][10][10] = {0};

int IsWin(int arr[10][10], int n, int x);

void Direction(int direction, int x, int i, int j, int n, int arr[10][10], int count[4][8], int result[]);

int main() {
    int t = 0;
    int x = 0;
    scanf("%d%d", &t, &x);
    int n[10] = {0};
    for (int i = 0; i < t; i++) {
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; j++) {
            for (int k = 0; k < n[i]; k++) {
                scanf("%d", &square[i][j][k]);
            }
        }
    }
    for (int i = 0; i < t; i++) {
        int result = IsWin(square[i], n[i], x);
        if (result == 0) {
            printf("draw\n");
        } else if (result > 0) {
            printf("%d\n", result);
        } else {
            if (result == -1) {
                printf("2 4\n");
            } else if (result == -2) {
                printf("1 4\n");
            } else {
                printf("1 2\n");
            }
        }
    }
    return 0;
}

int IsWin(int arr[10][10], int n, int x) {
    int result[4] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count[4][8] = {0};
            if (arr[i][j] != 0) {
                for (int k = 0; k < 8; k++) {
                    Direction(k, x, i, j, n, arr, count, result);
                }
            }
        }
    }
    int num = 0;
    for (int i = 0; i < 4; i++) {
        if (result[i] == 1) {
            num++;
        }
    }
    switch (num) {
        case 1:
            for (int i = 0; i < 4; i++) {
                if (result[i] == 1) {
                    return i + 1;
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                if (result[i] == 0 && i != 3) {
                    return -(i + 1);
                }
            }
            break;
        default:
            return 0;
    }
    return 0;
}

void Direction(int direction, int x, int i, int j, int n, int arr[10][10], int count[4][8], int result[]) {
    for (int k = 1; k <= x - 1; k++) {
        int newX;
        int newY;
        switch (direction) {
            case 0:
                newX = j;
                newY = i - k;
                break;
            case 1:
                newX = j;
                newY = i + k;
                break;
            case 2:
                newX = j - k;
                newY = i;
                break;
            case 3:
                newX = j + k;
                newY = i;
                break;
            case 4:
                newX = j + k;
                newY = i - k;
                break;
            case 5:
                newX = j - k;
                newY = i - k;
                break;
            case 6:
                newX = j + k;
                newY = i + k;
                break;
            case 7:
                newX = j - k;
                newY = i + k;
                break;
            default:
                newX = j;
                newY = i;
        }
        if (newX >= 0 && newX <= n - 1 && newY >= 0 && newY <= n - 1 && arr[newY][newX] == arr[i][j]) {
            count[arr[i][j] - 1][direction]++;
        }

    }
    if (count[arr[i][j] - 1][direction] == x - 1) {
        result[arr[i][j] - 1] = 1;
    }
}
