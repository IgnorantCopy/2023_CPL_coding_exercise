//
// Created by Ignorant on 2023/10/31.
//


#include <stdio.h>

int a[30000] = {0};
int b[30000] = {0};
int results[30000] = {0};

int main() {
    int k = 0;
    int m = 0;
    int n = 0;
    int index = 0;
    scanf("%d%d%d", &k, &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a[i], &b[i]);
        if ((a[i] != 0 && k / a[i] * b[i] >= n) || (a[i] == 0 && b[i] != 0)) {
            results[index++] = i + 1;
        }
    }
    if (index == 0) {
        printf("-1");
    } else {
        index = 0;
        while (results[index] != 0) {
            printf("%d ", results[index++]);
        }
    }
    return 0;
}
