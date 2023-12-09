//
// Created by Ignorant on 2023/12/9.
//


#include <stdio.h>
#include <string.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char num[65] = {0};
        scanf("%s", num);
        int len = strlen(num);
        if ((num[len - 1] - 48) % 2 == 0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }
    return 0;
}
