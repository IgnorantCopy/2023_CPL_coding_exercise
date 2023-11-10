//
// Created by Ignorant on 2023/11/10.
//


#include <stdio.h>

int Function();

int main() {
    int flag = Function();
    if (flag) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

int Function() {
    int stack = 0;
    char key = 0;
    while (key != '@') {
        scanf("%c", &key);
        if (key == '(') {
            stack++;
        } else if (key == ')') {
            stack--;
        }
        if (stack < 0) {
            return 0;
        }
    }
    return !stack;
}
