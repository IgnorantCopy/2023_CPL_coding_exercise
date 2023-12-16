//
// Created by Ignorant on 2023/12/15.
//


#include <stdio.h>
#include <stdlib.h>

int CompareInt(const void *num1, const void *num2);

int main() {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    int *nums = malloc(sizeof(*nums) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < q; i++) {
        int key = 0;
        scanf("%d", &key);
        int *key_ptr = &key;
        int *ptr = bsearch(key_ptr, nums, n, sizeof(nums[0]), CompareInt);
        if (ptr == NULL) {
            printf("-1\n");
        } else {
            printf("%d\n", ptr - nums);
        }
    }
    free(nums);
    return 0;
}

int CompareInt(const void *num1, const void *num2) {
    int left = *(const int *) num1;
    int right = *(const int *) num2;
    return (right < left) - (right > left);
}
