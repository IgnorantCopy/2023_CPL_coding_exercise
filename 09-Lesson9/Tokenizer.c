//
// Created by Ignorant on 2023/12/3.
//

#include <ctype.h>
#include <string.h>
#include <stdio.h>

int isReserved(const char *str);

int isInteger(const char *str);

int isFloat(const char *str);

int isOperator(const char *str);

int isVariable(const char *str);

int Search(const char *str);

int Process(const char *str);

char reserveds[16][10] = {"const", "int", "float", "double", "long", "static", "void",
                          "char", "extern", "return", "break", "enum", "struct",
                          "typedef", "union", "goto"};
char operators[11][3] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};
char types[5][10] = {"reserved ", "integer ", "float ", "operator ", "variable "};
char input[4096] = {0};
char output[4096][10] = {0};
int order = 0;

typedef int (*PtrFunctions)(const char *);

PtrFunctions functions[5] = {isReserved, isInteger, isFloat, isOperator, isVariable};

int main() {
    while (1) {
        memset(input, 0, 4096);
        if ((scanf("%s", input)) == EOF) {
            if (output[order - 1][0] != '\n') {
                printf("Compile Error\n");
                return 0;
            }
            break;
        }
        int index;
        start:
        index = Search(input);
        if (index == -1) {
            int isExit = Process(input);
            if (isExit == -1) {
                printf("Compile Error\n");
                return 0;
            }
        } else {
            char left[4096] = {0};
            char right[4096] = {0};
            strncpy(left, input, index);
            strcpy(right, input + index + 1);
            int isExit = Process(left);
            if (isExit == -1) {
                printf("Compile Error\n");
                return 0;
            }
            output[order++][0] = '\n';
            index = Search(right);
            if (index == -1) {
                isExit = Process(right);
                if (isExit == -1) {
                    printf("Compile Error\n");
                    return 0;
                }
            } else {
                memset(input, 0, 4096);
                strcpy(input, right);
                goto start;
            }
        }
    }
    for (int i = 0; i < order; i++) {
        printf("%s", output[i]);
    }
    return 0;
}

int isReserved(const char *str) {
    for (int i = 0; i < 16; i++) {
        if (!strcmp(str, reserveds[i])) {
            return 1;
        }
    }
    return 0;
}

int isInteger(const char *str) {
    for (int i = 0; *(str + i) != 0; i++) {
        if (!isdigit(*(str + i))) {
            return 0;
        }
    }
    return 1;
}

int isFloat(const char *str) {
    int countDot = 0;
    for (int i = 0; *(str + i) != 0; i++) {
        if (*(str + i) == '.' && !countDot) {
            countDot++;
        } else if (!isdigit(*(str + i))) {
            return 0;
        }
    }
    return 1;
}

int isOperator(const char *str) {
    for (int i = 0; i < 11; i++) {
        if (!strcmp(str, operators[i])) {
            return 1;
        }
    }
    return 0;
}

int isVariable(const char *str) {
    if (isdigit(*str)) {
        return 0;
    }
    for (int i = 0; *(str + i) != 0; i++) {
        if (!isdigit(*(str + i)) && !isalpha(*(str + i)) && *(str + i) != '_') {
            return 0;
        }
    }
    return 1;
}

int Search(const char *str) {
    for (int i = 0; *(str + i) != 0; i++) {
        if (*(str + i) == ';') {
            return i;
        }
    }
    return -1;
}

int Process(const char *str) {
    if (*str == 0) {
        return 0;
    }
    int type = -1;
    for (int i = 0; i < 5; i++) {
        if ((*functions[i])(str)) {
            type = i;
            break;
        }
    }
    if (type == -1) {
        return -1;
    }
    strcpy(output[order++], types[type]);
    return 0;
}
