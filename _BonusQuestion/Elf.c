//
// Created by Ignorant on 2023/12/13.
//

#include <stdio.h>
double theta0 = 1.000;
double theta1 = 1.000;

double h(double x);

int main() {
    int t = 2000;
    double alpha = 0.01;
    int m = 0;
    double input[100][2] = {0};
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lf%lf", &input[i][0], &input[i][1]);
    }
    for (int i = 0; i < t; i++) {
        double j0 = 0;
        double j1 = 0;
        for (int j = 0; j < m; j++) {
            j0 += (h(input[j][0]) - input[j][1]) / m;
            j1 += ((h(input[j][0]) - input[j][1]) * input[j][0]) / m;
        }
        theta0 -= alpha * j0;
        theta1 -= alpha * j1;
    }
    printf("y = %.3f + %.3fx", theta0, theta1);
    return 0;
}

double h(double x) {
    return theta0 + theta1 * x;
}
