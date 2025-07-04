//
// Created by Ignorant on 2023/12/26.
//


# include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 2000

typedef struct Node {
    char *content;
    struct Node *next;
    int length;
} Node;

Node Init(const char *input, int n);

void InsertNode(Node *head, int index);

void Delete(Node *head);

void I();

void Q();

int main() {
    int n = 0;
    int q = 0;
    char *input = malloc((n + 1) * sizeof(*input));
    scanf("%d%d%s", &n, &q, input);
    Node *head = Init(input, n);
    free(input);
    for (int i = 0; i < q; i++) {
        getchar();
        char key = 0;
        scanf("%c", &key);
        switch (key) {
            case 'I':
                I();
                break;
            case 'Q':
                Q();
                break;
            default:
                break;
        }
    }
    Delete(head);
    return 0;
}

void I() {

}

void Q() {

}

Node Init(const char *input, int n) {
    Node *head = NULL;
    Node *tail = malloc(sizeof(Node));
    tail->content = malloc((B + 1) * sizeof(char));
    tail->next = NULL;
    for (int i = 0, index = 0; i < n; i++) {
        if (index != B) {
        
        }
    }
    head = tail;
    return head;
}

void InsertNode(Node *head, int index) {

}

void Delete(Node *head) {
    while (head != NULL) {
        Node *temp = head->next;
        free(head->content);
        free(head);
        head = temp;
    }
}
