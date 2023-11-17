//
// Created by Ignorant on 2023/11/12.
//

#include <stdio.h>

long long Pascal(int a, int b);

int main() {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    printf("%lld", Pascal(a, b));
    return 0;
}

long long Pascal(int a, int b) {
    static long long pascal[36][36] = {0};
    if (a == 1 || b == 1 || b == a) {
        return 1;
    }
    if (pascal[a][b]) {
        return pascal[a][b];
    }
    pascal[a][b] = Pascal(a - 1, b - 1) + Pascal(a - 1, b);
    return pascal[a][b];
}
