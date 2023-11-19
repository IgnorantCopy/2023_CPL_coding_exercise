//
// Created by Ignorant on 2023/11/17.
//


#include <stdio.h>

int values[10000] = {0};
int ws[10000] = {0};

int main() {
    int n = 0;
    int L = 0;
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &ws[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (values[j] < values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
                temp = ws[j];
                ws[j] = ws[j + 1];
                ws[j + 1] = temp;
            }
        }
    }
    int volume = 0;
    int sum = 0;
    int index = 0;
    while (volume < L) {
        if (ws[index] <= L - volume) {
            volume += ws[index];
            sum += values[index] * ws[index];
            index++;
        } else {
            sum += values[index] * (L - volume);
            volume = L;
        }
    }
    printf("%d", sum);
    return 0;
}
