//
// Created by Ignorant on 2023/11/7.
//


#include <stdio.h>

int hight[20000] = {0};

int main() {
    int n = 0;
    int b = 0;
    int sum = 0;
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &hight[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hight[j] < hight[j + 1]) {
                int temp = hight[j];
                hight[j] = hight[j + 1];
                hight[j + 1] = temp;
            }
        }
    }
    int num = 0;
    while (sum < b) {
        sum += hight[num++];
    }
    printf("%d", num);
    return 0;
}
