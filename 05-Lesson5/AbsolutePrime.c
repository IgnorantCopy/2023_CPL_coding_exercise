//
// Created by Ignorant on 2023/10/27.
//


#include <stdio.h>

int reverse(int n);

int main() {
    int n = 0;
    int nums[1001] = {0};
    int count = 0;
    scanf("%d", &n);
    for (int i = 4; i <= 1000; i += 2) {
        nums[i] = 1;
    }
    for (int i = 3; i <= 1000; i += 2) {
        for (int j = i * 3; j <= 1000; j += 2 * i) {
            nums[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        int temp = reverse(i);
        if (nums[i] == 0 && nums[temp] == 0) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

int reverse(int n) {
    int ans = 0;
    while (n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}
