//
// Created by Ignorant on 2023/11/12.
//

#include <stdio.h>

int Tiles(int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d", Tiles(n));
    return 0;
}

int Tiles(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return Tiles(n - 1) + Tiles(n - 2);
}
