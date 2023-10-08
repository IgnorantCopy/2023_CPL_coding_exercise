//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>
#include <math.h>

int main() {
    int year;
    int month;
    int day;
    scanf("%d %d %d", &year, &month, &day);
    double a = floor(((14 - month) + 0.0) / 12);
    double y = year + 4800 - a;
    double m = month + 12 * a - 3;
    int JDN = day + floor((153 * m + 2) / 5) + 365 * y + floor(y / 4) - floor(y / 100) + floor(y / 400) - 32045;
    printf("%d", JDN);

    return 0;
}
