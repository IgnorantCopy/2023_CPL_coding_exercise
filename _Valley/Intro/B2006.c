//
// Created by Ignorant on 2023/11/10.
//


#include <stdio.h>

int main() {
    int x = 0;
    int a = 0;
    int y = 0;
    int b = 0;
    scanf("%d%d%d%d", &x, &a, &y, &b);
    double k = 1.0 * (b * y - a * x) / (b - a);
    printf("%.2f", k);
    return 0;
}
