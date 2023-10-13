//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>

int main() {
    int n = 0;
    int numbers[100] = {0};
    int marks[100] = {0};
    int single = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        marks[numbers[i]] += 1;
    }
    for (int i = 0; i < 100; i++) {
        if (marks[i] == 1) {
            printf("%d", i);
        }
    }
    return 0;
}
