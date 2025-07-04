//
// Created by Ignorant on 2023/12/25.
//


#include <stdio.h>
#include <string.h>

int Check(const char *input, const char *output, int len1, int len2);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n = 0;
        int count = 0;
        scanf("%d", &n);
        char input[100001] = {0};
        scanf("%s", input);
        char output[200001] = {0};
        scanf("%s", output);
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            if (input[j] == '?' && input[k] == '?') {
                count += 2;
            } else if (input[j] == '?') {
                input[j] = input[k];
            } else if (input[k] == '?') {
                input[k] = input[j];
            }
        }
        if (Check(input, output, n, n + count)) {
            printf("Correct.\n");
        } else {
            printf("Wrong Answer!\n");
        }
    }
    return 0;
}

int Check(const char *input, const char *output, int len1, int len2) {
    if (strlen(output) != len2) {
        return 0;
    }
    int nums[10][10] = {0};
    for (int i = 0, j = 0; i < len1; i++, j++) {
        if (input[i] != '?' && input[i] != output[j]) {
            return 0;
        } else if (input[i] == '?') {
            if (output[j] >= 48 && output[j] < 58 && output[j + 1] >= 48 && output[j + 1] < 58) {
                if (nums[output[j] - 48][output[j + 1] - 48] == 2 ||
                    (output[j] != output[len2 - j - 1] && output[j + 1] != output[len2 - j - 2])) {
                    return 0;
                }
                nums[output[j] - 48][output[j + 1] - 48]++;
                j++;
            } else {
                return 0;
            }
        }
    }
    return 1;
}
