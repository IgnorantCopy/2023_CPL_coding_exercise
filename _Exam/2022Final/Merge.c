//
// Created by Ignorant on 2023/12/26.
//


#include <stdio.h>
#include <stdlib.h>

int nums1[200000] = {0};
int nums2[200000] = {0};

int FindMax(const int *nums, int length);

int main() {
    int len1 = 0;
    int len2 = 0;
    scanf("%d", &len1);
    for (int i = 0; i < len1; i++) {
        scanf("%d", &nums1[i]);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; i++) {
        scanf("%d", &nums2[i]);
    }
    int *newNums = malloc((len1 + len2) * sizeof(*newNums));
    int maxIndex1 = FindMax(nums1, len1);
    int maxIndex2 = FindMax(nums2, len2);
    // merge1
    int left1 = 0;
    int left2 = 0;
    int index = 0;
    while (left1 <= maxIndex1 && left2 <= maxIndex2) {
        if (nums1[left1] < nums2[left2]) {
            newNums[index++] = nums1[left1++];
        } else {
            newNums[index++] = nums2[left2++];
        }
    }
    while (left1 <= maxIndex1) {
        newNums[index++] = nums1[left1++];
    }
    while (left2 <= maxIndex2) {
        newNums[index++] = nums2[left2++];
    }
    // merge2
    while (left1 < len1 && left2 < len2) {
        if (nums1[left1] > nums2[left2]) {
            newNums[index++] = nums1[left1++];
        } else {
            newNums[index++] = nums2[left2++];
        }
    }
    while (left1 < len1) {
        newNums[index++] = nums1[left1++];
    }
    while (left2 < len2) {
        newNums[index++] = nums2[left2++];
    }
    for (int i = 0; i < index; i++) {
        printf("%d ", newNums[i]);
    }
    free(newNums);
    return 0;
}

int FindMax(const int *nums, int length) {
    int max = nums[0];
    for (int i = 0; i < length - 1; i++) {
        if (nums[i + 1] < max) {
            return i;
        }
        max = nums[i + 1];
    }
    return length - 1;
}
