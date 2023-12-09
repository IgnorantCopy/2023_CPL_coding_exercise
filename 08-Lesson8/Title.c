//
// Created by Ignorant on 2023/11/26.
//


#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str = malloc(sizeof(*str) * 4096);
    while ((scanf("%s", str)) != EOF) {
        *str = toupper(*str);
        for (int i = 1; *(str + i) != 0; i++) {
            *(str + i) = tolower(*(str + i));
        }
        printf("%s ", str);
    }
    free(str);
    return 0;
}
