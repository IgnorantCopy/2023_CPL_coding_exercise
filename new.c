//
// Created by Ignorant on 2023/12/27.
//


#include<stdio.h>
#include<string.h>


int main() {
    char s[10] = "a;;b;;c";
    char str[] = ";;";
    char *p = strtok(s, str);
    char *q = strtok(s + strlen(str) + 1, str);
    printf("%s\n%s", p, q);
    return 0;
}

