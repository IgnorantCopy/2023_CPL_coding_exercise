//
// Created by Ignorant on 2023/11/19.
//


#include <stdio.h>
#include <string.h>

char stack[10001] = {0};

int isEqual(const char target[], const char str[]);

void Push();

void Pop();

void Top();

void Print();

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char operation[6] = {0};
        scanf("%s", operation);
        if (isEqual(operation, "push")) {
            Push();
        } else if (isEqual(operation, "pop")) {
            Pop();
        } else if (isEqual(operation, "top")) {
            Top();
        } else if (isEqual(operation, "print")) {
            Print();
        }
    }
    return 0;
}

int isEqual(const char target[], const char str[]) {
    int len1 = strlen(target);
    int len2 = strlen(str);
    if (len1 != len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (target[i] != str[i]) {
            return 0;
        }
    }
    return 1;
}

void Push() {
    int length = strlen(stack);
    char key = 0;
    getchar();
    scanf("%c", &key);
    stack[length] = key;
}

void Pop() {
    int length = strlen(stack);
    if (length == 0) {
        printf("Empty\n");
    } else {
        stack[length - 1] = 0;
    }
}

void Top() {
    int length = strlen(stack);
    if (length == 0) {
        printf("Empty\n");
    } else {
        printf("%c\n", stack[length - 1]);
    }
}

void Print() {
    int length = strlen(stack);
    if (length == 0) {
        printf("Empty\n");
    } else {
        for (int i = length - 1; i >= 0; i--) {
            printf("| %c |\n", stack[i]);
        }
        printf("|===|\n");
    }
}
