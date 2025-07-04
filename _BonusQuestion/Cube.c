//
// Created by Ignorant on 2023/12/13.
//


#include <stdio.h>
#include <string.h>

int nums[600][100] = {0};

void IntCpy(int *dest, const int *src, int length);

int main() {
    char operator[15] = {0};
    int n = 0;
    scanf("%s %d", operator, &n);
    for (int i = 0; i < 6 * n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    if (!strcmp("rotate", operator)) {
        int side = 0;
        scanf("%d", &side);
        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int j = (n + 1) / 2; j < n; j++) {
                int add = n * side;
                int temp = nums[i + add][j];
                nums[i + add][j] = nums[n - 1 - j + add][i];
                nums[n - 1 - j + add][i] = nums[n - 1 - i + add][n - 1 - j];
                nums[n - 1 - i + add][n - 1 - j] = nums[j + add][n - 1 - i];
                nums[j + add][n - 1 - i] = temp;
            }
        }
    } else if (!strcmp("line-rotate", operator)) {
        int record[4] = {0};
        for (int i = 0; i < 4; i++) {
            int side = 0;
            int line = 0;
            scanf("%d%d", &side, &line);
            int index = n * side + line;
            record[i] = index;
        }
        int temp[100] = {0};
        IntCpy(temp, nums[record[0]], n);
        IntCpy(nums[record[0]], nums[record[3]], n);
        IntCpy(nums[record[3]], nums[record[2]], n);
        IntCpy(nums[record[2]], nums[record[1]], n);
        IntCpy(nums[record[1]], temp, n);
    }
    for (int i = 0; i < 6 * n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void IntCpy(int *dest, const int *src, int length) {
    for (int i = 0; i < length; i++) {
        *(dest + i) = *(src + i);
    }
}
