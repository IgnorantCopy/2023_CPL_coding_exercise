//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>
#include <math.h>

int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    double newP = p;
    double newQ = q;
    double delta = pow(newQ / 2, 2) + pow(newP / 3, 3);
    double result = cbrt(-newQ / 2 + sqrt(delta)) + cbrt(-newQ / 2 - sqrt(delta));
    printf("%.3lf", result);
    return 0;
}
