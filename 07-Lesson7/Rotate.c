//
// Created by Ignorant on 2023/11/18.
//


#include <stdio.h>
#include <string.h>

char operate[1001] = {0};
int a = 0;
int b = 0;
int c = 0;
int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;

void W();

void A();

void S();

void D();

int main() {
    scanf("%d%d%d", &a, &b, &c);
    x2 = a;
    y2 = b;
    scanf("%s", operate);
    int length = strlen(operate);
    for (int i = 0; i < length; i++) {
        char key = operate[i];
        switch (key) {
            case 'W':
                W();
                break;
            case 'A':
                A();
                break;
            case 'S':
                S();
                break;
            case 'D':
                D();
                break;
        }
    }
    printf("%d %d %d %d", x1, x2, y1, y2);
    return 0;
}

void W() {
    x2 -= a;
    int temp = a;
    a = c;
    c = temp;
    x1 -= a;
}

void A() {
    y2 -= b;
    int temp = b;
    b = c;
    c = temp;
    y1 -= b;
}

void S() {
    x1 += a;
    int temp = a;
    a = c;
    c = temp;
    x2 += a;
}

void D() {
    y1 += b;
    int temp = b;
    b = c;
    c = temp;
    y2 += b;
}
