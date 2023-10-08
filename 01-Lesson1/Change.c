//
// Created by Ignorant on 2023/10/8.
//


#include <stdio.h>

int main() {
    int money = 0;
    scanf("%d", &money);
    if (money >= 0 && money <= 10000) {
        int fifties = money / 50;
        money -= fifties * 50;
        int twenties = money / 20;
        money -= twenties * 20;
        int tens = money / 10;
        money -= tens * 10;
        int fives = money / 5;
        money -= fives * 5;
        int ones = money;
        printf("%d\n%d\n%d\n%d\n%d\n", fifties, twenties, tens, fives, ones);
    }
    return 0;
}
