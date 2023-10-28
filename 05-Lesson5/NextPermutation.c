//
// Created by Ignorant on 2023/10/28.
//


#include <stdio.h>

int main() {
    int n = 0;
    int m = 1;
    int index = 0;
    int nums[2001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        if (nums[i - 1] > nums[i]) {
            m++;
        } else {
            index = i - 1;
            break;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (nums[i] > nums[index]) {
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            break;
        }
    }
    for (int i = index + 1, j = n - 1; i <= j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
