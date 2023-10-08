//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>
#include <math.h>

int main() {
    double Pi1 = (log(pow(640320, 3) + 744)) / sqrt(163);
    double Pi2 = 16 * atan(1.0 / 5) - 4 * atan(1.0 / 239);
    printf("%.15f\n%.15f\n", Pi1, Pi2);
    return 0;
}
