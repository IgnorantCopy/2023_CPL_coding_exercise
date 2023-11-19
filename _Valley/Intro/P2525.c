//
// Created by Ignorant on 2023/10/31.
//


#include <stdio.h>

int girls[9] = {0};
int results[9] = {0};

int Cantos(const int arr[], int length);

int Factorial(int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &girls[i]);
    }
    int nums[9] = {0};
    int num = Cantos(girls, n) - 1;
    for (int i = n - 1; i > 0; i--) {
        int count = 0;
        int index = i;
        int minus;
        int ans;
        do {
            minus = index * Factorial(i);
            index--;
        } while (minus > num);
        num -= minus;
        for (int j = 0; j < n; j++) {
            if (count == index + 1) {
                while (nums[j] == 1) {
                    j++;
                }
                ans = j + 1;
                break;
            }
            if (nums[j] == 0) {
                count++;
            }
        }
        results[n - 1 - i] = ans;
        nums[ans - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            results[n - 1] = i + 1;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", results[i]);
    }
    return 0;
}

int Cantos(const int arr[], int length) {
    int nums[9] = {0};
    int ans = 0;
    for (int i = 0; i < length; i++) {
        int count = 0;
        nums[arr[i] - 1] = 1;
        for (int j = 0; j < arr[i] - 1; j++) {
            if (nums[j] == 0) {
                count++;
            }
        }
        ans += count * Factorial(length - 1 - i);
    }
    return ans;
}

int Factorial(int n) {
    if (n > 1) {
        return n * Factorial(n - 1);
    }
    return 1;
}
