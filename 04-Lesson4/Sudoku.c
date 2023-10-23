//
// Created by Ignorant on 2023/10/21.
//

#include <stdio.h>
int arr[9][9] = {0};
int test1[9][10] = {0};
int test2[9][10] = {0};
int test3[9][10] = {0};

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i % 3 == 1 && j % 3 == 1) {
                test3[index3][arr[i - 1][j - 1]]++;
                test3[index3][arr[i - 1][j]]++;
                test3[index3][arr[i - 1][j + 1]]++;
                test3[index3][arr[i][j - 1]]++;
                test3[index3][arr[i][j]]++;
                test3[index3][arr[i][j + 1]]++;
                test3[index3][arr[i + 1][j - 1]]++;
                test3[index3][arr[i + 1][j]]++;
                test3[index3][arr[i + 1][j + 1]]++;
                for (int k = 1; k < 10; k++) {
                    if (test3[index3][k] >= 2) {
                        printf("NO");
                        goto end;
                    }
                }
                index3++;
            }
            test1[index1][arr[i][j]]++;
            test2[index2][arr[j][i]]++;
            if (test1[index1][arr[i][j]] >= 2) {
                printf("NO");
                goto end;
            }
            if (test2[index2][arr[j][i]] >= 2) {
                printf("NO");
                goto end;
            }
        }
        index1++;
        index2++;
    }
    printf("YES");
    end:

    return 0;
}
