//
// Created by Ignorant on 2023/12/2.
//


#include <stdio.h>

int balances[3] = {0};
int bills[100] = {0};

int K(int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bills[i]);
    }
    if (K(n)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}

int K(int n) {
    for (int i = 0; i < n; i++) {
        switch (bills[i]) {
            case 5:
                balances[0]++;
                break;
            case 10:
                if (balances[0] == 0) {
                    return 0;
                }
                balances[0]--;
                balances[1]++;
                break;
            case 20:
                if (balances[1] != 0 && balances[0] != 0) {
                    balances[1]--;
                    balances[0]--;
                } else if (balances[0] >= 3) {
                    balances[0] -= 3;
                } else {
                    return 0;
                }
                balances[2]++;
                break;
        }
    }
    return 1;
}
