//
// Created by Ignorant on 2023/12/13.
//


#include <stdio.h>
#include <string.h>

int nums[600][3] = {0};

int main() {
    char operator[15] = {0};
    int n = 0;
    scanf("%s %d", operator, &n);
    for (int i = 0; i < 6 * n; i++) {
        scanf("%d%d%d", &nums[i][0], &nums[i][1], &nums[i][2]);
    }
    if (!strcmp("rotate", operator)) {
        int side = 0;
        scanf("%d", &side);
        int y = 3 * side;
        int x = 0;
        int temp = nums[y][x];
        nums[y][x] = nums[y + 2][x];
        nums[y + 2][x] = nums[y + 2][x + 2];
        nums[y + 2][x + 2] = nums[y][x + 2];
        nums[y][x + 2] = temp;
        temp = nums[y][x + 1];
        nums[y][x + 1] = nums[y + 1][x];
        nums[y + 1][x] = nums[y + 2][x + 1];
        nums[y + 2][x + 1] = nums[y + 1][x + 2];
        nums[y + 1][x + 2] = temp;
    } else if (!strcmp("line-rotate", operator)) {
        int rotate[4][2] = {0};
        int record[4] = {0};
        for (int i = 0; i < 4; i++) {
            scanf("%d%d", &rotate[i][0], &rotate[i][1]);
            int index = 3 * rotate[i][0] + rotate[i][1];
            record[i] = index;
        }
        int temp[3] = {nums[record[0]][0], nums[record[0]][1], nums[record[0]][2]};
        nums[record[0]][0] = nums[record[3]][0];
        nums[record[0]][1] = nums[record[3]][1];
        nums[record[0]][2] = nums[record[3]][2];
        nums[record[3]][0] = nums[record[2]][0];
        nums[record[3]][1] = nums[record[2]][1];
        nums[record[3]][2] = nums[record[2]][2];
        nums[record[2]][0] = nums[record[1]][0];
        nums[record[2]][1] = nums[record[1]][1];
        nums[record[2]][2] = nums[record[1]][2];
        nums[record[1]][0] = temp[0];
        nums[record[1]][1] = temp[1];
        nums[record[1]][2] = temp[2];
    }
    for (int i = 0; i < 6 * n; i++) {
        printf("%d %d %d\n", nums[i][0], nums[i][1], nums[i][2]);
    }
    return 0;
}
