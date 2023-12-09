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
    const char *temp = str1;
    while ((temp = strstr(temp, str2)) != NULL) {
        printf("%d ", temp - str1);
        temp++;
    }
    free(str1);
    free(str2);
    return 0;
}
