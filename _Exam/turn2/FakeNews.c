//
// Created by Ignorant on 2023/12/9.
//

#include <stdio.h>

int main() {
    char input[1024] = {0};
    scanf("%s", input);
    int index = 1;
    char output[2048] = {*input};
    for (int i = 1; *(input + i) != 0; i++) {
        if (*(input + i) >= 'A' && *(input + i) <= 'Z') {
            output[index++] = ' ';
            output[index++] = *(input + i) + 32;
        } else {
            output[index++] = *(input + i);
        }
    }
    printf("%s", output);
    return 0;
}
