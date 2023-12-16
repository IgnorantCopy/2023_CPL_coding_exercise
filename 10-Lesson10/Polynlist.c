//
// Created by Ignorant on 2023/12/15.
//


#include <stdio.h>

char name[11] = {0};

void Add(const int coefficient1[], const int coefficient2[], int len1, int len2);

void Minus(const int coefficient1[], const int coefficient2[], int len1, int len2);

void Multiply(const int coefficient1[], const int coefficient2[], int len1, int len2);

void Print(int coefficient[], int size);

int main() {
    int p1 = 0;
    int p2 = 0;
    scanf("%d%d", &p1, &p2);
    scanf("%s", name);
    int coefficient1[10001] = {0};
    int coefficient2[10001] = {0};
    for (int i = 0; i < p1 + 1; i++) {
        scanf("%d", &coefficient1[i]);
    }
    for (int i = 0; i < p2 + 1; i++) {
        scanf("%d", &coefficient2[i]);
    }
    Add(coefficient1, coefficient2, p1, p2);
    Minus(coefficient1, coefficient2, p1, p2);
    Multiply(coefficient1, coefficient2, p1, p2);
    return 0;
}

void Add(const int coefficient1[], const int coefficient2[], int len1, int len2) {
    int coefficient3[10001] = {0};
    int size = 0;
    for (int i = len1, j = len2; i >= 0 || j >= 0; i--, j--) {
        coefficient3[size++] = (i >= 0 ? coefficient1[i] : 0) + (j >= 0 ? coefficient2[j] : 0);
    }
    Print(coefficient3, size);
}

void Minus(const int coefficient1[], const int coefficient2[], int len1, int len2) {
    int coefficient3[10001] = {0};
    int size = 0;
    for (int i = len1, j = len2; i >= 0 || j >= 0; i--, j--) {
        coefficient3[size++] = (i >= 0 ? coefficient1[i] : 0) - (j >= 0 ? coefficient2[j] : 0);
    }
    Print(coefficient3, size);
}

void Multiply(const int coefficient1[], const int coefficient2[], int len1, int len2) {
    int coefficient3[20001] = {0};
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            coefficient3[len1 + len2 - i - j] += coefficient1[i] * coefficient2[j];
        }
    }
    int size = len1 + len2 + 1;
    Print(coefficient3, size);
}

void Print(int coefficient[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = coefficient[i];
        coefficient[i] = coefficient[j];
        coefficient[j] = temp;
    }
    for (int i = 0; i < size; i++) {
        if (i != 0 && coefficient[i] > 0) {
            printf("+");
        }
        if (i == size - 2 && coefficient[i] != 0) {
            if (coefficient[i] == 1) {
                printf("%s", name);
            } else if (coefficient[i] == -1) {
                printf("-%s", name);
            } else {
                printf("%d%s", coefficient[i], name);
            }
        } else if (i == size - 1 && coefficient[i] != 0) {
            printf("%d", coefficient[i]);
        } else if (coefficient[i] != 0) {
            if (coefficient[i] == 1) {
                printf("%s^%d", name, size - 1 - i);
            } else if (coefficient[i] == -1) {
                printf("-%s^%d", name, size - 1 - i);
            } else {
                printf("%d%s^%d", coefficient[i], name, size - 1 - i);
            }
        }
    }
    printf("\n");
}
