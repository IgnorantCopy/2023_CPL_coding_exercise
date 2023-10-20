//
// Created by Ignorant on 2023/9/27.
//

#include <stdio.h>
#include <time.h>
#define N 50000001

int flag[N] = {0};
int primes[3001134] = {2};

int main() {
    time_t start = time(NULL);  //time_t 类型是 long long 类型
    long int n = 0;
    long int sum = 0;
    scanf("%ld", &n);
    for (int i = 2; i < n + 1; i++) {
        if (flag[i] == 0) {
            primes[sum++] = i;
        }
        for (int j = 0; j < sum && i * primes[j] <= n; j++) {
            flag[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    printf("%ld", sum);
    time_t end = time(NULL);
    printf("%lld", end - start);
    return 0;
}
