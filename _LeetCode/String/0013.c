//
// Created by Ignorant on 2023/10/10.
//

#include <stdio.h>

int main() {
    char s[15] = {0};
    scanf("%s", s);
    const char ONE = 'I';
    const char FIVE = 'V';
    const char TEN = 'X';
    const char FIFTY = 'L';
    const char ONE_HUNDRED = 'C';
    const char FIVE_HUNDRED = 'D';
    const char ONE_THOUSAND = 'M';
    int num = 0;
    int temp = 0;
    int flag1;
    int flag2;
    for (int i = 0; i < sizeof(s); i++) {
        switch (s[i]) {
            case ONE:
                flag1 = 1;
                break;
            case FIVE:
                flag1 = 5;
                break;
            case TEN:
                flag1 = 10;
                break;
            case FIFTY:
                flag1 = 50;
                break;
            case ONE_HUNDRED:
                flag1 = 100;
                break;
            case FIVE_HUNDRED:
                flag1 = 500;
                break;
            case ONE_THOUSAND:
                flag1 = 1000;
                break;
        }
        if (i < sizeof(s) - 1) {
            switch (s[i + 1]) {
                case ONE:
                    flag2 = 1;
                    break;
                case FIVE:
                    flag2 = 5;
                    break;
                case TEN:
                    flag2 = 10;
                    break;
                case FIFTY:
                    flag2 = 50;
                    break;
                case ONE_HUNDRED:
                    flag2 = 100;
                    break;
                case FIVE_HUNDRED:
                    flag2 = 500;
                    break;
                case ONE_THOUSAND:
                    flag2 = 1000;
                    break;
            }
        }
        if (flag1 < flag2) {
            temp = -num;
        }
        num += flag1;
    }
    return 0;
}
