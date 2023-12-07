//
// Created by Ignorant on 2023/11/19.
//


#include <stdio.h>
#include <string.h>

char stack[10001] = {0};

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
        if (!strcmp(operation, "push")) {
            Push();
        } else if (!strcmp(operation, "pop")) {
            Pop();
        } else if (!strcmp(operation, "top")) {
            Top();
        } else if (!strcmp(operation, "print")) {
            Print();
        }
    }
    return 0;
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
