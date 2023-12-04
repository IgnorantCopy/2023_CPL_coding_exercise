//
// Created by Ignorant on 2023/12/2.
//


#include <stdio.h>
#include <string.h>

char rule[128] = {0};
char input[1024] = {0};
char argv[1024][1024] = {0};
char output[1024][1024] = {0};
char alpha[128] = {0};

int main() {
    scanf("%s", rule);
    getchar();
    scanf("%[^\n]", input);
    for (int i = 0; *(rule + i) != 0; i++) {
        if (*(rule + i) == ':') {
            alpha[*(rule + i - 1)]++;
        } else {
            alpha[*(rule + i)]++;
        }
    }
    int argc = 0;
    int isAlpha = 1;
    int index = 0;
    for (int i = 0; *(input + i) != 0; i++) {
        if (*(input + i) != ' ' && !isAlpha) {
            argc++;
            index = 0;
            isAlpha = 1;
        }
        if (*(input + i) != ' ') {
            argv[argc][index++] = *(input + i);
        } else if (*(input + i) == ' ' && isAlpha) {
            isAlpha = 0;
        }
    }
    index = 1;
    strcpy(output[0], argv[0]);
    for (int i = 0; i <= argc; i++) {
        int len = strlen(argv[i]);
        if (argv[i][0] == '-' && len == 2) {
            char key = argv[i][1];
            if (alpha[key] == 0) {
                printf("%s: invalid option -- '%c'", argv[0], key);
                return 0;
            } else if (alpha[key] == 1) {
                output[index++][0] = key;
            } else if (alpha[key] == 2) {
                if (i == argc) {
                    printf("%s: option requires an argument -- '%c'", argv[0], key);
                    return 0;
                } else {
                    output[index][0] = key;
                    output[index][1] = '=';
                    i++;
                    for (int j = 0; argv[i][j] != 0; j++) {
                        output[index][j + 2] = argv[i][j];
                    }
                    index++;
                }
            }
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%s\n", output[i]);
    }
    return 0;
}
