//
// Created by Ignorant on 2023/10/22.
//


#include <stdio.h>

char argv[1001] = {0};
int alpha[2][26] = {0};

int main() {
    int n = 0;
    int max = 0;
    scanf("%d", &n);
    scanf("%s", argv);
    for (int i = 0; i < n; i++) {
        if (argv[i] >= 'A' && argv[i] <= 'Z') {
            alpha[1][argv[i] - 65]++;
            max = max > alpha[1][argv[i] - 65] ? max : alpha[1][argv[i] - 65];
        } else if (argv[i] >= 'a' && argv[i] <= 'z') {
            alpha[0][argv[i] - 97]++;
            max = max > alpha[0][argv[i] - 97] ? max : alpha[0][argv[i] - 97];
        }
    }
    int isExist;
    int count = 0;
    for (; max > 0; max--) {
        for (int i = 0; i < 26; i++) {
            isExist = 0;
            for (int j = 0; j < 2; j++) {
                if (alpha[j][i] >= max) {
                    printf("=");
                    if (max == 1) {
                        count++;
                    }
                    isExist = 1;
                } else if (alpha[j][i] != 0) {
                    printf(" ");
                    if (max == 1) {
                        count++;
                    }
                    isExist = 1;
                }
            }
            if (isExist) {
                printf(" ");
                if (max == 1) {
                    count++;
                }
            }
        }
        printf("\n");
    }
    for (int i = 0; i < count - 1; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 26; i++) {
        isExist = 0;
        for (int j = 0; j < 2; j++) {
            if (alpha[j][i] != 0) {
                printf("%c", i + (j == 0 ? 97 : 65));
                isExist = 1;
            }
        }
        if (isExist) {
            printf(" ");
        }
    }
    return 0;
}
