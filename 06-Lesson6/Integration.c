//
// Created by Ignorant on 2023/11/12.
//


#include <stdio.h>
#include <math.h>
#define LIMIT 0.0004

int as[21] = {0};
int n = 0;
int p = 0;

double Func(double x);

double S(double left, double right);

double Integration(double left, double right, double limit);

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &as[i]);
    }
    double a = 0;
    double b = 0;
    scanf("%lf%lf", &a, &b);
    printf("%f", Integration(a, b, LIMIT));
    return 0;
}

double Func(double x) {
    double sum = 0;
    for (int i = 0; i < n + 1; i++) {
        sum += as[i] * pow(x, i);
    }
    return pow(sum, p);
}

double S(double left, double right) {
    return ((4 * Func((left + right) / 2) + Func(left) + Func(right)) / 6) * (right - left);
}

double Integration(double left, double right, double limit) {
    double mid = (left + right) / 2;
    double s = S(left, right);
    double sl = S(left, mid);
    double sr = S(mid, right);
    if (fabs(sl + sr - s) <= 15 * limit) {
        return sl + sr + (sl + sr - s) / 15;
    }
    return Integration(left, mid, limit / 2) + Integration(mid, right, limit / 2);
}
