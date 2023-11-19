//
// Created by Ignorant on 2023/11/18.
//


#include <stdio.h>


int va = 0;
int vb = 0;
int vc = 0;
int a0 = 0;
int b0 = 0;
int c0 = 0;

int Pour(int k, int a, int b, int c);

int main() {
    int k = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
    int flag = Pour(k, a, b, c);
    if (flag) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}

int Pour(int k, int a, int b, int c) {
    if (a == a0 && b == b0 && c == c0) {
        return 1;
    }
    if (k == 0) {
        return 0;
    }
    int recordA = a;
    int recordB = b;
    int recordC = c;
    // a --> b
    a = 0;
    b = (recordA + recordB) <= vb ? (recordA + recordB) : vb;
    c = recordC;
    int flag1 = Pour(k - 1, a, b, c);
    // a --> c
    a = 0;
    b = recordB;
    c = (recordA + recordC) <= vc ? (recordA + recordC) : vc;
    int flag2 = Pour(k - 1, a, b, c);
    // b --> a
    a = (recordA + recordB) <= va ? (recordA + recordB) : va;
    b = 0;
    c = recordC;
    int flag3 = Pour(k - 1, a, b, c);
    // b --> c
    a = recordA;
    b = 0;
    c = (recordB + recordC) <= vc ? (recordB + recordC) : vc;
    int flag4 = Pour(k - 1, a, b, c);
    // c --> a
    a = (recordA + recordC) <= va ? (recordA + recordC) : va;
    b = recordB;
    c = 0;
    int flag5 = Pour(k - 1, a, b, c);
    // c --> b
    a = recordA;
    b = (recordB + recordC) <= vb ? (recordB + recordC) : vb;
    c = 0;
    int flag6 = Pour(k - 1, a, b, c);
    return flag1 || flag2 || flag3 || flag4 || flag5 || flag6;
}