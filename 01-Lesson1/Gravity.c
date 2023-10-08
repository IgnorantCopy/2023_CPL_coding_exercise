//
// Created by Ignorant on 2023/10/8.
//

#include <stdio.h>

#define G 6.674e-11
#define M 77.15

int main() {
    double m;
    double r;
    scanf("%lf %lf", &m, &r);
    double F = (G * M * m) / (r * r);
    printf("%.3e", F);
    return 0;
}
