//
// Created by Ignorant on 2023/10/21.
//

#include <stdio.h>
char arr[2000][2000] = {0};
char newArr[2000][2002] = {0};

int main() {
    int m = 0;
    int n = 0;
    scanf("%d%d", &m, &n);
    scanf("%s", arr[0]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i != 0) {
                newArr[i][j] = '0';
            } else if (j == 0 || j == n + 1) {
                newArr[i][j] = '0';
            } else {
                newArr[i][j] = arr[i][j - 1];
            }
        }
    }
    int count = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n + 1; j++) {
            count = newArr[i - 1][j - 1] + newArr[i - 1][j] + newArr[i - 1][j + 1] - 48 * 3;
            if (count == 0 || count == 3 || (count == 1 && newArr[i - 1][j - 1] == '1')) {
                newArr[i][j] = '0';
            } else if (count == 2 || count == 1) {
                newArr[i][j] = '1';
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n + 1; j++) {
            printf("%c", newArr[i][j]);
        }
        if (i != m - 1) {
            printf("\n");
        }
    }
    return 0;
}
