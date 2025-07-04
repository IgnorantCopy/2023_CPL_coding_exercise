//
// Created by Ignorant on 2023/12/29.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *last;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *bottom;
    Node *top;
} Stack;

void Init(Stack *stack, int index);

void Free(Stack *stack);

int IsEmpty(const Stack *stack);

void Print(const Stack *stack);

void Pour(Stack *x, Stack *y);

int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    Stack *stacks = malloc(n * sizeof(Stack));
    if (stacks == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        Init(stacks + i, i);
    }
    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        scanf("%d%d", &x, &y);
        Pour(stacks + x - 1, stacks + y - 1);
    }
    for (int i = 0; i < n; i++) {
        Print(stacks + i);
    }
    for (int i = n - 1; i >= 0; i--) {
        Free(stacks + i);
    }
    free(stacks);
    return 0;
}

void Init(Stack *stack, int index) {
    stack->bottom = NULL;
    stack->top = NULL;
    Node *node = malloc(sizeof(Node));
    node->num = index + 1;
    node->next = NULL;
    node->last = NULL;
    stack->bottom = node;
    stack->top = node;
}

void Free(Stack *stack) {
    if (IsEmpty(stack)) {
        return;
    }
    Node *node = stack->bottom;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
}

int IsEmpty(const Stack *stack) {
    return NULL == stack->bottom;
}

void Print(const Stack *stack) {
    if (IsEmpty(stack)) {
        printf("0\n");
        return;
    }
    Node *node = stack->bottom;
    while (node != NULL) {
        printf("%d ", node->num);
        node = node->next;
    }
    printf("\n");
}

void Pour(Stack *x, Stack *y) {
    if (IsEmpty(x)) {
        return;
    }
    Node *node1 = x->top;
    while (node1 != NULL) {
        Node *node2 = malloc(sizeof(Node));
        node2->num = node1->num;
        Node *temp = node1;
        node1 = node1->last;
        x->top = node1;
        free(temp);
        node2->next = NULL;
        node2->last = y->top;
        if (!IsEmpty(y)) {
            y->top->next = node2;
        } else {
            y->bottom = node2;
        }
        y->top = node2;
    }
    x->bottom = NULL;
}
