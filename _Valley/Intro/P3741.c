//
// Created by Ignorant on 2023/12/9.
//


#include <stdio.h>
#include <string.h>

int flag = 0;

int Solve(const char *arr, int length);

int main() {
    int n = 0;
    char input[101] = {0};
    scanf("%d", &n);
    scanf("%s", input);
    printf("%d", Solve(input, n));
    return 0;
}

int Solve(const char *arr, int length) {
    if (length == 1) {
        return 0;
    }
    const char *temp = strstr(arr, "VK");
    if (temp == NULL) {
        for (int i = 0; i < length - 1; i++) {
            if (flag == 1) {
                return 0;
            } else if (arr[i] == arr[i + 1]) {
                flag = 1;
                return 1;
            }
        }
    } else {
        char left[100] = {0};
        char right[100] = {0};
        strncpy(left, arr, temp - arr);
        strcpy(right, temp + 2);
        return 1 + Solve(left, temp - arr) + Solve(right, length - 2 - (temp - arr));
    }
    return 0;
}
