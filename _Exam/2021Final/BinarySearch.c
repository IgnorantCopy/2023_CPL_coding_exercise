//
// Created by Ignorant on 2023/12/31.
//


#include <stdio.h>
#include <stdlib.h>

int BSearch(const int *nums, int target, int length);

int main() {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    int *nums = malloc(n * sizeof(*nums));
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    for (int i = 0; i < q; i++) {
        int target = 0;
        scanf("%d", &target);
        printf("%d\n", BSearch(nums, target, n));
    }
    free(nums);
    return 0;
}

int BSearch(const int *nums, int target, int length) {
    int left = 0;
    int right = length - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (*(nums + mid) > target) {
            right = mid - 1;
        } else if (*(nums + mid) < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

