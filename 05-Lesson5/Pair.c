//
// Created by Ignorant on 2023/10/28.
//


#include <stdio.h>

int nums1[1000000] = {0};
int nums2[1000000] = {0};

int pair(const int arr1[], const int arr2[], int target, int len1, int len2);

int main() {
    int n = 0;
    int m = 0;
    int t = 0;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums2[i]);
    }
    printf("%d", pair(nums1, nums2, t, n, m));
    return 0;
}

int pair(const int arr1[], const int arr2[], int target, int len1, int len2) {
    int min = -1;
    int isStart = 0;
    for (int i = 0; i < len2; i++) {
        int left = 0;
        int right = len1 - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            int temp = target - arr1[mid] - arr2[i];
            if (temp < 0) {
                right = mid - 1;
            } else if (temp > 0) {
                left = mid + 1;
                if (!isStart) {
                    min = temp;
                    isStart = 1;
                } else {
                    min = min < temp ? min : temp;
                }
            } else {
                return 0;
            }
            mid = (left + right) / 2;
        }

    }
    return min;
}
