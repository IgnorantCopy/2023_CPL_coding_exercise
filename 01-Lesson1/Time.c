//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>

int main() {
    char month[15], weekday[15];
    int day, year, hour, minute, second;
    scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
    if (year >= 0 && year <= 9999) {
        printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", weekday, month, day, hour, minute, second, year);
    }
    return 0;
}
