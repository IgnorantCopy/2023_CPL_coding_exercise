//
// Created by Ignorant on 2023/11/26.
//


#include <stdio.h>

int main() {
    int num1 = 0;
    int *ptr1 = &num1;
    scanf("%x", ptr1);
    printf("%d\n", *ptr1);
    printf("%u\n", *ptr1);
    float *ptr2 = &num1;
    printf("%.6f\n", *ptr2);
    printf("%.3e\n", *ptr2);
    return 0;
}
