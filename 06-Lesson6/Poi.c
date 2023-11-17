//
// Created by Ignorant on 2023/11/12.
//


#include <stdio.h>

int id[100000] = {0};

int Poi(int n, int index);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", Poi(id[i], i));
    }
    return 0;
}

int Poi(int n, int index) {
    if (n == index) {
        return index;
    }
    return Poi(id[id[index]], id[index]);
}
