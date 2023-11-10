//
// Created by Ignorant on 2023/10/31.
//

#include <stdio.h>

int Cantos(const char arr[], int length);

int Factorial(int n);

int main() {
    int n = 0;
    char x[10] = {0};
    scanf("%d", &n);
    scanf("%s", x);
    printf("%d", Cantos(x, n));
    return 0;
}

int Cantos(const char arr[], int length) {
    int nums[9] = {0};
    int ans = 0;
    for (int i = 0; i < length; i++) {
        int count = 0;
        nums[arr[i] - 49] = 1;
        for (int j = 0; j < arr[i] - 49; j++) {
            if (nums[j] == 0) {
                count++;
            }
        }
        ans += count * Factorial(length - 1 - i);
    }
    return ans + 1;
}

int Factorial(int n) {
    if (n > 1) {
        return n * Factorial(n - 1);
    }
    return 1;
}
