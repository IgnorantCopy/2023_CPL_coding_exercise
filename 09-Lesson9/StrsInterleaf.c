//
// Created by Ignorant on 2023/12/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *InterleaveString(const char *s1, const char *s2, char *target, int ds1, int ds2, int size);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char s1[1001] = {0};
        char s2[1001] = {0};
        char *input = malloc(sizeof(*input) * 2020);
        scanf("%s", input);
        int n = strlen(input);
        for (int j = 0; *input != ';'; input++, j++) {
            s1[j] = *input;
        }
        input++;
        for (int j = 0; *input != ';'; input++, j++) {
            s2[j] = *input;
        }
        input++;
        char temp1[5] = {0};
        for (int j = 0; *input != ';'; input++, j++) {
            temp1[j] = *input;
        }
        input++;
        int ds1 = atoi(temp1);
        char temp2[5] = {0};
        for (int j = 0; *input != ';'; input++, j++) {
            temp2[j] = *input;
        }
        input++;
        int ds2 = atoi(temp2);
        char temp3[5] = {0};
        for (int j = 0; *input != '\0'; input++, j++) {
            temp3[j] = *input;
        }
        int size = atoi(temp3);
        char target[2001] = {0};
        printf("%s\n", InterleaveString(s1, s2, target, ds1, ds2, size));
        free(input - n);
    }
    return 0;
}

char *InterleaveString(const char *s1, const char *s2, char *target, int ds1, int ds2, int size) {
    int index = 0;
    while (1) {
        for (int i = 0; i < ds1; i++, s1++) {
            if (*s1 != '\0' && index < size - 1) {
                *(target + index++) = *s1;
            } else {
                break;
            }
        }
        if (index == size - 1) {
            return target;
        }
        for (int i = 0; i < ds2; i++, s2++) {
            if (*s2 != '\0' && index < size - 1) {
                *(target + index++) = *s2;
            } else {
                break;
            }
        }
        if (index == size - 1 || (*s1 == 0 && *s2 == 0)) {
            return target;
        }
    }
}
