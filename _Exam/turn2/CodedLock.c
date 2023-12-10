//
// Created by Ignorant on 2023/12/9.
//

#include <stdio.h>

int password[1000] = {0};

int Row(int num1, int num2, int n, int d);

int main() {
    int w = 0;
    int n = 0;
    int d = 0;
    scanf("%d%d%d", &w, &n, &d);
    for (int i = 0; i < w; i++) {
        scanf("%d", &password[i]);
    }
    int count = 0;
    for (int i = 0, j = w - 1; i < j; i++, j--) {
        int add = Row(password[i], password[j], n, d);
        if (add == -1) {
            printf("Impossible");
            return 0;
        }
        count += add;
    }
    printf("%d", count);
    return 0;
}

int Row(int num1, int num2, int n, int d) {
    int count1 = 0;
    while (num1 != num2) {
        if (count1 == n) {
            return -1;
        }
        num1 = (num1 + d - 1) % n + 1;
        count1++;
    }
    int count2 = n - count1;
    return count1 < count2 ? count1 : count2;
}

