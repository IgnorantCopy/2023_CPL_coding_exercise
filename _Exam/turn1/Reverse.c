//
// Created by Ignorant on 2023/10/29.
//


#include <stdio.h>

char input[100005] = {0};
char output[100005] = {0};

int main() {
    int len = 0;
    scanf("%d", &len);
    scanf("%s", input);
    for (int i = 0; i < len; i++) {
        if (input[len - 1 - i] >= 'a' && input[len - 1 - i] <= 'z') {
            output[i] = input[len - 1 - i] - 32;
        } else if (input[len - 1 - i] >= 'A' && input[len - 1 - i] <= 'Z') {
            output[i] = input[len - 1 - i] + 32;
        } else {
            output[i] = input[len - 1 - i];
        }
    }
    printf("%s", output);
    return 0;
}
