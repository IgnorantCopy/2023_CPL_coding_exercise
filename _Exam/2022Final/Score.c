//
// Created by Ignorant on 2023/12/28.
//


#include <stdio.h>
#include <stdlib.h>

int nums[9] = {0};
int bs[3] = {0};

int CompareInt(const void *num1, const void *num2);

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d%d%d", &bs[0], &bs[1], &bs[2]);
    qsort(bs, 3, sizeof(bs[0]), CompareInt);
    int scoreMax = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            for (int k = j + 1; k < 9; k++) {
                if ((k - j == 3 && j - i == 3) || (k / 3 == j / 3 && j / 3 == i / 3) ||
                    (i == 0 && j == 4 && k == 8) || (i == 2 && j == 4 && k == 6)) {
                    continue;
                }
                int temp[3] = {nums[i], nums[j], nums[k]};
                qsort(temp, 3, sizeof(temp[0]), CompareInt);
                int score = temp[0] * bs[0] + temp[1] * bs[1] + temp[2] * bs[2];
                scoreMax = score > scoreMax ? score : scoreMax;
            }
        }
    }
    printf("%d", scoreMax);
    return 0;
}

int CompareInt(const void *num1, const void *num2) {
    const int *left = num1;
    const int *right = num2;
    return (*left < *right) - (*left > *right);
}


