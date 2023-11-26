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
    // a --> b
    int flag1 = Pour(k - 1, 0, (a + b) <= vb ? (a + b) : vb, c);
    // a --> c
    int flag2 = Pour(k - 1, 0, b, (a + c) <= vc ? (a + c) : vc);
    // b --> a
    int flag3 = Pour(k - 1, (a + b) <= va ? (a + b) : va, 0, c);
    // b --> c
    int flag4 = Pour(k - 1, a, 0, (b + c) <= vc ? (b + c) : vc);
    // c --> a
    int flag5 = Pour(k - 1, (a + c) <= va ? (a + c) : va, b, 0);
    // c --> b
    int flag6 = Pour(k - 1, a, (b + c) <= vb ? (b + c) : vb, 0);
    return flag1 || flag2 || flag3 || flag4 || flag5 || flag6;
}