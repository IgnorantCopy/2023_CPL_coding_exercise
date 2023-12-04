//
// Created by Ignorant on 2023/12/2.
//


#include <stdio.h>

int stack[1000] = {0};
int in[1000] = {0};
int out[1000] = {0};

int B(int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &out[i]);
    }
    if (B(n)) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}

int B(int n) {
    int index = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
        stack[index] = in[j];
        j++;
        index++;
        while (stack[index - 1] == out[i] && i < n) {
            stack[index - 1] = 0;
            i++;
            index--;
        }
    }
    if (index == 0) {
        return 1;
    }
    return 0;
}
