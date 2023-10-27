//
// Created by Ignorant on 2023/10/27.
//


#include <stdio.h>
#include <string.h>

void print_l1(int col) {
    for (int i = 0; i < col; i++) {
        if (i % 12 == 10) {
            printf("*");
        } else if (i % 4 == 2) {
            printf("#");
        } else {
            printf(".");
        }
    }
}

void print_l2(int col) {
    for (int i = 0; i < col / 4; i++) {
        if (i % 3 == 2) {
            printf(".*.*");
        } else {
            printf(".#.#");
        }
    }
    printf(".\n");
}

int main() {
    char input[16] = {0};
    scanf("%s", input);
    int len = strlen(input);
    int col = 4 * len + 1;
    int index = 0;
    print_l1(col);
    printf("\n");
    print_l2(col);
    for (int i = 0; i < col / 2; i++) {
        if (i % 2 == 1) {
            printf("%c.", input[index++]);
        } else if (i % 6 == 4) {
            if (index == len - 1) {
                printf("*.%c.*", input[index++]);
            } else {
                printf("*.%c.*.", input[index++]);
            }
            i += 2;
        } else {
            printf("#.");
        }
    }
    if (len % 3 != 0) {
        printf("#\n");
    } else {
        printf("\n");
    }
    print_l2(col);
    print_l1(col);
    return 0;
}
