//
// Created by Ignorant on 2023/11/26.
//


#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str = malloc(sizeof(*str) * 4096);
    gets(str);
    *str = toupper(*(str));
    for (int i = 1; i < strlen(str); i++) {
        if (*(str + i - 1) == ' ') {
            *(str + i) = toupper(*(str + i));
        } else if (*(str + i) != ' ') {
            *(str + i) = tolower(*(str + i));
        }
    }
    printf("%s", str);
    free(str);
    return 0;
}
