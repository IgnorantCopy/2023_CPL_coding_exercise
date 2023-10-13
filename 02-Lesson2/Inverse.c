//
// Created by Ignorant on 2023/10/9.
//


#include <stdio.h>

int main() {
    int n = 0;
    char string[1000] = {0};
    char result[1000] = {0};
    char test[1000] = {0};
    int k = 0;
    scanf("%d\n", &n);
    int index = 0;
    while ((test[index] = getchar()) != '\n') {
        index++;
    }
    if (index != n) {
        for (int i = 0; i < n - index; i++) {
            string[i] = ' ';
        }
    }
    for (int i = n - index, j = 0; i < n; i++, j++) {
        string[i] = test[j];
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        result[i] = string[k - 1 - i];
    }
    for (int i = k; i < n; i++) {
        result[i] = string[n - 1 - i + k];
    }
    printf("%s", result);
    return 0;
}
