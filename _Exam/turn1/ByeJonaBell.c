//
// Created by Ignorant on 2023/10/29.
//


#include <stdio.h>

int bell[1500] = {0};

int main() {
    int n = 0;
    int k = 0;
    long long int b = 0;
    int l = 0;
    int index = 0;
    int count = 0;
    scanf("%d%d%lld%d", &n, &k, &b, &l);
    for (int i = 0; i < n; i++) {
        bell[i] = l;
    }
    long long int newB = b;
    int alive = n;
    while (alive != 1) {
        if (count == k - 1) {
            if (newB != 0) {
                while (bell[index] == 0) {
                    index = (index + 1) % n;
                }
                newB--;
                bell[index]--;
                if (bell[index] == 0) {
                    alive--;
                }
            } else {
                newB = b;
            }
        }
        index = (index + 1) % n;
        while (bell[index] == 0) {
            index = (index + 1) % n;
        }
        count = (count + 1) % k;
    }
    for (int i = 0; i < n; i++) {
        if (bell[i] != 0) {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}
