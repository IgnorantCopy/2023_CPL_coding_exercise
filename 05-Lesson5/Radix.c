//
// Created by Ignorant on 2023/10/27.
//


#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int Decimal(int r, int i);

int GetB(int p, int q, int r, int begin);

int GetMax(int num);

int main() {
    int p = 0;
    int q = 0;
    int r = 0;
    scanf("%d%d%d", &p, &q, &r);
    int max = MAX(GetMax(p), MAX(GetMax(q), GetMax(r)));
    printf("%d", GetB(p, q, r, max));
    return 0;
}

int Decimal(int r, int i) {
    int ge = r % 10;
    int shi = r / 10;
    return shi * i + ge;
}

int GetB(int p, int q, int r, int begin) {
    for (int i = MAX(2, begin + 1); i < 41; i++) {
        int temp = Decimal(p, i) * Decimal(q, i);
        if (Decimal(r, i) == temp) {
            return i;
        }
    }
    return 0;
}

int GetMax(int num) {
    int ge = num % 10;
    int shi = num / 10;
    return MAX(ge, shi);
}
