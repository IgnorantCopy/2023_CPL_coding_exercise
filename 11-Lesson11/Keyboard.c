//
// Created by Ignorant on 2023/12/30.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char key;
    struct Node *last;
    struct Node *next;
} Node;

typedef struct DoubleLinkedList {
    Node *head;
    Node *tail;
    Node *lastUpper;
    Node *lastLower;
} DoubleLinkedList;

void Init(DoubleLinkedList *list);

void Free(DoubleLinkedList *list);

int IsEmpty(const DoubleLinkedList *list);

int IsSingleton(const DoubleLinkedList *list);

void Query(DoubleLinkedList *list, int k);

void Dom(DoubleLinkedList *list);

void DoM(DoubleLinkedList *list);

void AddToEnd(DoubleLinkedList *list, char key);

void Add(DoubleLinkedList *list, const char *input);

int main() {
    int q = 0;
    scanf("%d", &q);
    DoubleLinkedList list;
    Init(&list);
    for (int i = 0; i < q; i++) {
        char input[2000001];
        scanf("%s", input);
        if (input[0] == '?') {
            int k = 0;
            scanf("%d", &k);
            Query(&list, k);
        } else {
            Add(&list, input);
        }
    }
    Free(&list);
    return 0;
}

void Init(DoubleLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->lastLower = NULL;
    list->lastUpper = NULL;
}

void Free(DoubleLinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
}

int IsEmpty(const DoubleLinkedList *list) {
    return list->head == NULL;
}

int IsSingleton(const DoubleLinkedList *list) {
    return !IsEmpty(list) && list->head == list->tail;
}

void Query(DoubleLinkedList *list, int k) {
    Node *node = list->tail;
    for (int i = 0; i < k - 1; i++) {
        node = node->last;
    }
    while (node != NULL) {
        printf("%c", node->key);
        node = node->next;
    }
    printf("\n");
}

void Dom(DoubleLinkedList *list) {
    Node *node1 = list->lastLower;
    if (IsEmpty(list) || node1 == NULL) {
        return;
    }
    if (IsSingleton(list)) {
        free(node1);
        Init(list);
    } else {
        Node *node2 = node1->last;
        Node *node3 = node1->next;
        if (node1 == list->tail) {
            node2->next = NULL;
            list->tail = node2;
        } else if (node1 == list->head) {
            node3->last = NULL;
            list->head = node3;
        } else {
            node3->last = node1->last;
            node2->next = node1->next;
        }
        free(node1);
        while (node2 != NULL) {
            if (node2->key >= 'a' && node2->key <= 'z') {
                break;
            }
            node2 = node2->last;
        }
        list->lastLower = node2;
    }
}

void DoM(DoubleLinkedList *list) {
    Node *node1 = list->lastUpper;
    if (IsEmpty(list) || node1 == NULL) {
        return;
    }
    if (IsSingleton(list)) {
        free(node1);
        Init(list);
    } else {
        Node *node2 = node1->last;
        Node *node3 = node1->next;
        if (node1 == list->tail) {
            node2->next = NULL;
            list->tail = node2;
        } else if (node1 == list->head) {
            node3->last = NULL;
            list->head = node3;
        } else {
            node3->last = node1->last;
            node2->next = node1->next;
        }
        free(node1);
        while (node2 != NULL) {
            if (node2->key >= 'A' && node2->key <= 'Z') {
                break;
            }
            node2 = node2->last;
        }
        list->lastUpper = node2;
    }
}

void AddToEnd(DoubleLinkedList *list, char key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    if (key >= 'a' && key <= 'z') {
        list->lastLower = node;
    } else if (key >= 'A' && key <= 'Z') {
        list->lastUpper = node;
    }
    node->next = NULL;
    if (IsEmpty(list)) {
        node->last = NULL;
        list->head = node;
    } else {
        list->tail->next = node;
        node->last = list->tail;
    }
    list->tail = node;
}

void Add(DoubleLinkedList *list, const char *input) {
    for (int i = 0; *(input + i) != 0; i++) {
        switch (*(input + i)) {
            case 'm':
                Dom(list);
                break;
            case 'M':
                DoM(list);
                break;
            default:
                AddToEnd(list, *(input + i));
                break;
        }
    }
}
