//
// Created by Ignorant on 2023/11/7.
//


#include <stdio.h>

int nums[1000001] = {0};
int results[1000001] = {0};

int main() {
    int n = 0;
    int m = 0;
    int p = 0;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++) {
        int k = 0;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int temp = 0;
            scanf("%d", &temp);
            nums[temp]++;
        }
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        if (nums[i] == p) {
            results[sum++] = i;
        }
    }
    printf("%d\n", sum);
    sum = 0;
    while (results[sum] != 0) {
        printf("%d ", results[sum++]);
    }
    return 0;
}
