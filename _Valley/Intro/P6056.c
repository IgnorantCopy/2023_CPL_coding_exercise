//
// Created by Ignorant on 2023/12/9.
//


#include <stdio.h>
#include <math.h>

int main() {
    int s = 0;
    int i = 0;
    int r = 0;
    int n = 0;
    scanf("%d%d%d", &s, &i, &n);
    const int sum = s + i;
    double beta = 0;
    double gamma = 0;
    scanf("%lf%lf", &beta, &gamma);
    for (int j = 0; j < n; j++) {
        int newI = ceil(beta * s * i);
        int newR = ceil(gamma * i);
        if (newI < s) {
            s -= newI;
            i = i + newI - newR;
        } else {
            i = i + s - newR;
            s = 0;
        }
        r = r + newR;
    }
    printf("%d %d %d", s, i, r);
    return 0;
}
