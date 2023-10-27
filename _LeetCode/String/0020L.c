//
// Created by Ignorant on 2023/10/25.
//

#include <stdio.h>
#include <string.h>

int numsOfBrackets[3][2] = {0};
char vectors[7] = {'(', ')', '[', ']', '{', '}'};
char s[10001] = {0};

int main() {
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i] == vectors[j]) {
                numsOfBrackets[j / 2][j % 2]++;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (numsOfBrackets[i][0] != numsOfBrackets[i][1]) {
            printf("false");
        }
    }
    printf("true");
    return 0;
}
