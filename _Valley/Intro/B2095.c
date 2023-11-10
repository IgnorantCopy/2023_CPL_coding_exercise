//
// Created by Ignorant on 2023/11/10.
//


#include <stdio.h>
#include <math.h>

double sample[300] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    scanf("%lf", &sample[0]);
    double max = sample[0];
    double min = sample[0];
    double sum = sample[0];
    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        scanf("%lf", &sample[i]);
        sum += sample[i];
        if (sample[i] > max) {
            max = sample[i];
            maxIndex = i;
        } else if (sample[i] < min) {
            min = sample[i];
            minIndex = i;
        }
    }
    double average = (sum - max - min) / (n - 2);
    max = 0;
    for (int i = 0; i < n; i++) {
        if (i != maxIndex && i != minIndex) {
            double delta = fabs(sample[i] - average);
            max = max > delta ? max : delta;
        }
    }
    printf("%.2f %.2f", average, max);
    return 0;
}
