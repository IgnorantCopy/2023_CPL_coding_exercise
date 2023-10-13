//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>
#include <math.h>

int main() {
    double x = 0.0;
    int n = 0;
    scanf("%lf %d", &x, &n);
    double result = 0.0;
    for (int i = 0; i <= n; i++) {
        result += (pow(-1, i) * pow(x, 2 * i + 1)) / (2 * i + 1);
    }
    printf("%.10f", 4 * result);
    return 0;
}
