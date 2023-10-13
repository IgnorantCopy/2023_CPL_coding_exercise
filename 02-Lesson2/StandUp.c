//
// Created by Ignorant on 2023/10/9.
//

#include <stdio.h>

int main() {
    int n = 0;
    int min = 0;
    int sum = 0;
    scanf("%d", &n);
    int students[10001] = {0};
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &students[i]);
        if (sum < i) {
            sum++;
            min++;
        }
        sum += students[i];
    }
    printf("%d", min);
    return 0;
}
