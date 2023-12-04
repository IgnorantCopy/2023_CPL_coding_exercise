//
// Created by Ignorant on 2023/10/29.
//


#include <stdio.h>

char argv[100005] = {0};
char output[100005] = {0};

int main() {
    int len = 0;
    scanf("%d", &len);
    scanf("%s", argv);
    for (int i = 0; i < len; i++) {
        if (argv[len - 1 - i] >= 'a' && argv[len - 1 - i] <= 'z') {
            output[i] = argv[len - 1 - i] - 32;
        } else if (argv[len - 1 - i] >= 'A' && argv[len - 1 - i] <= 'Z') {
            output[i] = argv[len - 1 - i] + 32;
        } else {
            output[i] = argv[len - 1 - i];
        }
    }
    printf("%s", output);
    return 0;
}
