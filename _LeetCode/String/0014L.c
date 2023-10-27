//
// Created by Ignorant on 2023/10/24.
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    char strs[201][201] = {0};
    int strsSize = -1;
    while ((scanf("%s", strs[++strsSize])) != EOF) {}
    char result[201] = {0};
    int isSame = 1;
    int index = 0;
    while (isSame) {
        char compare = strs[0][index];
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][index] != compare) {
                isSame = 0;
                break;
            } else if (i == strsSize - 1) {
                result[index] = compare;
            }
        }
        index++;
    }
    if (result[0] == 0) {
        printf("");
    } else {
        printf("%s", result);
    }
    return 0;
}
