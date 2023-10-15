//
// Created by Ignorant on 2023/10/14.
//


#include <stdio.h>

int main() {
    int n = 0;
    int k = 0;
    int start = 0;
    int sum = 0;
    int isDead[500] = {0};
    scanf("%d%d", &n, &k);
    while (sum != n - 1){
        int count = 1;
        while (count <= k) {
            if (count == k && isDead[start] == 0) {
                isDead[start] = 1;
                count++;
                sum++;
            } else if (isDead[start] == 0) {
                count++;
            }
            start++;
            if (start == n) {
                start = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (isDead[i] == 0) {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}