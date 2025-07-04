//
// Created by Ignorant on 2023/12/30.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

void Init(LinkedList *list);

void Free(LinkedList *list);

int isEmpty(const LinkedList *list);

void Add(LinkedList *list, int num);

void Put(LinkedList *list, int index);

int IsSorted(LinkedList *list);

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        scanf("%d%d", &n, &m);
        LinkedList list;
        Init(&list);
        for (int j = 0; j < n; j++) {
            int num = 0;
            scanf("%d", &num);
            Add(&list, num);
        }
        for (int j = 0; j < m; j++) {
            int x = 0;
            scanf("%d", &x);
            Put(&list, x);
        }
        if (IsSorted(&list)) {
            printf("I love C programming language\n");
        } else {
            printf("mayi is a good teacher\n");
        }
        Free(&list);
    }
    return 0;
}

void Init(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

void Free(LinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
}

int isEmpty(const LinkedList *list) {
    return list->head == NULL;
}

void Add(LinkedList *list, int num) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->num = num;
    if (isEmpty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void Put(LinkedList *list, int index) {
    if (index <= 1) {
        return;
    }
    Node *node = list->head;
    for (int i = 0; i < index - 2 && node != NULL; i++) {
        node = node->next;
    }
    Node *target = node->next;
    if (target == list->tail) {
        list->tail = node;
    }
    node->next = node->next->next;
    target->next = list->head;
    list->head = target;
}

int IsSorted(LinkedList *list) {
    Node *node = list->head;
    while (node != list->tail) {
        if (node->num > node->next->num) {
            return 0;
        }
        node = node->next;
    }
    return 1;
}
