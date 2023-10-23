//
// Created by Ignorant on 2023/10/22.
//

#include <stdio.h>
#include <string.h>

char arr[1001] = {0};
char newArr[1007] = {0};
char update[1007] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        newArr[i + 3] = arr[i];
        update[i + 3] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 3; j < len + 3; j++) {
            int countA = (newArr[j - 3] == 'A' ? 1 : 0) +
                         (newArr[j - 2] == 'A' ? 1 : 0) +
                         (newArr[j - 1] == 'A' ? 1 : 0) +
                         (newArr[j + 1] == 'A' ? 1 : 0) +
                         (newArr[j + 2] == 'A' ? 1 : 0) +
                         (newArr[j + 3] == 'A' ? 1 : 0);
            int countB = (newArr[j - 3] == 'B' ? 1 : 0) +
                         (newArr[j - 2] == 'B' ? 1 : 0) +
                         (newArr[j - 1] == 'B' ? 1 : 0) +
                         (newArr[j + 1] == 'B' ? 1 : 0) +
                         (newArr[j + 2] == 'B' ? 1 : 0) +
                         (newArr[j + 3] == 'B' ? 1 : 0);
            if (newArr[j] == '.') {
                if (countA >= 2 && countA <= 4 && countB == 0) {
                    update[j] = 'A';
                } else if (countB >= 2 && countB <= 4 && countA == 0) {
                    update[j] = 'B';
                }
            } else if (newArr[j] == 'A' && (countB != 0 || countA >= 5 || countA <= 1)) {
                update[j] = '.';
            } else if (newArr[j] == 'B' && (countA != 0 || countB >= 5 || countB <= 1)) {
                update[j] = '.';
            }
        }
        for (int j = 3; j < len + 3; j++) {
            newArr[j] = update[j];
        }
    }
    for (int i = 3; i < len + 3; i++) {
        printf("%c", update[i]);
    }
    return 0;
}
