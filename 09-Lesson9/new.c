//
// Created by Ignorant on 2023/12/2.
//

#include <stdio.h> //字符串拼接
#include <string.h>


int main() {
    char left[4096] = {0};
    char right[4096] = {0};
    char input[] = "abcd;";
    int index = 4;
    strncpy(left, input, index);
    strcpy(right, input + index + 1);
    printf("%s\n%s", left, right);
    return 0;
}
