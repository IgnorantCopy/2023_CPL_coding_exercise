//
// Created by Ignorant on 2023/11/12.
//


#include <stdio.h>

int nums[100000] = {0};
int ans[100000][2] = {0};

void Max(int left, int right);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    Max(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}

void Max(int left, int right) {
    int l = left;
    int r = right;
    while (l != r) {
        if (nums[l] > nums[r]) {
            r--;
        } else {
            l++;
        }
    }
    ans[l][0] = left + 1;
    ans[l][1] = right + 1;
    if (l != left) {
        Max(left, l - 1);
    }
    if (l != right) {
        Max(l + 1, right);
    }
}
