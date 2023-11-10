//
// Created by Ignorant on 2023/11/9.
//

#include <stdio.h>
#include <string.h>
char str[10001] = {0};

void InsertLast(char string[]);

void Cut(char string[]);

void Insert(char string[]);

int Find(const char string[]);

int main() {
    int q = 0;
    scanf("%d", &q);
    scanf("%s", str);
    for (int i = 0; i < q; i++) {
        int key = 0;
        scanf("%d", &key);
        switch (key) {
            case 1:
                InsertLast(str);
                break;
            case 2:
                Cut(str);
                break;
            case 3:
                Insert(str);
                break;
            case 4:
                printf("%d\n", Find(str));
                break;
        }
    }
    return 0;
}

void InsertLast(char string[]) {
    scanf("%s", string + strlen(string));
    printf("%s\n", string);
}

void Cut(char string[]) {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < b; i++) {
        string[i] = string[a + i];
    }
    string[b] = 0;
    printf("%s\n", string);
}

void Insert(char string[]) {
    int a = 0;
    scanf("%d", &a);
    char input[101] = {0};
    scanf("%s", input);
    int oldLength = strlen(string);
    int len = strlen(input);
    for (int i = oldLength - 1; i >= a; i--) {
        string[i + len] = string[i];
    }
    for (int i = 0; i < len; i++) {
        string[i + a] = input[i];
    }
    string[oldLength + len] = 0;
    printf("%s\n", string);
}

int Find(const char string[]) {
    char input[101] = {0};
    scanf("%s", input);
    int len = strlen(input);
    for (int i = 0; i < strlen(string); i++) {
        int index = 0;
        while (string[i + index] == input[index]) {
            index++;
            if (index == len) {
                return i;
            }
        }
    }
    return -1;
}
