//
// Created by Ignorant on 2023/10/10.
//

#include <stdio.h>
#include <string.h>

int main() {
    char s[15] = {0};
    scanf("%s", s);
    int temp = 0;
    int num = 0;
    int flag1;
    int flag2;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'I':
                flag1 = 1;
                break;
            case 'V':
                flag1 = 5;
                break;
            case 'X':
                flag1 = 10;
                break;
            case 'L':
                flag1 = 50;
                break;
            case 'C':
                flag1 = 100;
                break;
            case 'D':
                flag1 = 500;
                break;
            case 'M':
                flag1 = 1000;
                break;
        }
        if (i < strlen(s) - 1) {
            switch (s[i + 1]) {
                case 'I':
                    flag2 = 1;
                    break;
                case 'V':
                    flag2 = 5;
                    break;
                case 'X':
                    flag2 = 10;
                    break;
                case 'L':
                    flag2 = 50;
                    break;
                case 'C':
                    flag2 = 100;
                    break;
                case 'D':
                    flag2 = 500;
                    break;
                case 'M':
                    flag2 = 1000;
                    break;
            }
        }
        num += flag1;
        if (flag1 < flag2) {
            temp = -num;
        }
    }
    printf("%d", num + 2 * temp);
    return 0;
}
