//
// Created by Ignorant on 2023/11/26.
//


#include <malloc.h>
#include <stdio.h>
#include <string.h>

int main() {
    char *str1 = malloc(sizeof(*str1) * 100000);
    char *str2 = malloc(sizeof(*str2) * 100000);
    scanf("%s", str1);
    scanf("%s", str2);
    for (int i = 0; i <= strlen(str1) - strlen(str2); i++) {
        int isSame = 1;
        for (int j = 0; j < strlen(str2); j++) {
            if (*(str2 + j) != *(str1 + i + j)) {
                isSame = 0;
                break;
            }
        }
        if (isSame) {
            printf("%d ", i);
        }
    }
    free(str1);
    free(str2);
    return 0;
}
