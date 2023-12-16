//
// Created by Ignorant on 2023/12/15.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[10005] = {0};

int CompareStr(const void *str1, const void *str2);

int main() {
    char key[5] = {0};
    scanf("%s", str);
    scanf("%s", key);
    char **output = malloc(101 * sizeof(*output));
    for (int i = 0; i < 101; i++) {
        output[i] = malloc(101 * sizeof(**output));
    }
    int len = 0;
    char *newStr = malloc(sizeof(*newStr) * 10005);
    memset(newStr, 0, 10005);
    strcpy(newStr, str);
    char *split;
    int index = 0;
    while ((split = strtok(str, key)) != NULL) {
        strcpy(output[index++], split);
        len += strlen(split) + 1;
        strcpy(str, newStr + len);
    }
    qsort(output, index, sizeof(output[0]), CompareStr);
    for (int i = 0; i < index; i++) {
        printf("%s\n", output[i]);
    }
    for (int i = 0; i < 101; i++) {
        free(output[i]);
    }
    free(output);
    free(newStr);
    return 0;
}

int CompareStr(const void *str1, const void *str2) {
    const char *const *str1_ptr = str1;
    const char *const *str2_ptr = str2;
    return strcmp(*str1_ptr, *str2_ptr);
}
