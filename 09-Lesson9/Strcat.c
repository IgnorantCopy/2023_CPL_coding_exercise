//
// Created by Ignorant on 2023/12/2.
//

#include <stdio.h>

void MyStrcat(char *s1, const char *s2);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char str1[1001] = {0};
        char str2[1001] = {0};
        scanf("%s %s", str1, str2);
        MyStrcat(str1, str2);
    }
    return 0;
}

void MyStrcat(char *s1, const char *s2) {
    int start = 0;
    int isFind = 0;
    const char *str1 = s1;
    while (!isFind) {
        for (; *str1 != *s2 && *str1 != '\0'; str1++) {
            start++;
        }
        int i = 0;
        for (; *(str1 + i) != '\0'; i++) {
            if (*(str1 + i) != *(s2 + i)) {
                break;
            }
        }
        if (*(str1 + i) == 0) {
            isFind = 1;
        } else {
            str1++;
            start++;
        }
    }
    for (int j = 0; *(s2 + j) != '\0'; start++, j++) {
        *(s1 + start) = *(s2 + j);
    }
    if (*(s1 + start) != '\0') {
        *(s1 + start) = 0;
    }
    printf("%s\n", s1);
}
