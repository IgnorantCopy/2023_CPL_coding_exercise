//
// Created by Ignorant on 2023/11/17.
//


#include <stdio.h>
#include <string.h>

char string[31][100001] = {0};
char stack[31][100001] = {0};

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", string[i]);
    }
    for (int i = 0; i < t; i++) {
        int length = strlen(string[i]);
        int index = 0;
        int flag = 1;
        for (int j = 0; j < length; j++) {
            char key = string[i][j];
            switch (key) {
                case '(':
                case '[':
                case '{':
                    stack[i][index++] = key;
                    break;
                case ')':
                    if (index == 0 || stack[i][index - 1] != '(') {
                        printf("False\n");
                        flag = 0;
                        j = length;
                    } else {
                        stack[i][--index] = 0;
                    }
                    break;
                case ']':
                    if (index == 0 || stack[i][index - 1] != '[') {
                        printf("False\n");
                        flag = 0;
                        j = length;
                    } else {
                        stack[i][--index] = 0;
                    }
                    break;
                case '}':
                    if (index == 0 || stack[i][index - 1] != '{') {
                        printf("False\n");
                        flag = 0;
                        j = length;
                    } else {
                        stack[i][--index] = 0;
                    }
                    break;
            }
        }
        if (flag == 1) {
            if (stack[i][0] != 0) {
                printf("False\n");
            } else {
                printf("True\n");
            }
        }
    }
    return 0;
}
