//
// Created by Ignorant on 2023/12/9.
//


#include <stdio.h>
#include <math.h>

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    scanf("%lf%lf%lf", &a, &b, &c);
    double p = (a + b + c) / 2;
    printf("%.1f", sqrt(p) * sqrt(fabs(p - a)) * sqrt(fabs(p - b)) * sqrt(fabs(p - c)));
    return 0;
}
