//
// Created by Nicholas Yang on 10/30/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* key;
    int value;
    struct node* next;
};

struct node* newNode(char* key, int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return(node);
}

struct node* append(struct node* list, struct node* newNode) {
    if (list->next == NULL) {
        list->next = newNode;
    } else {
        append(list->next, newNode);
    }
    return list;
}
// Different from append because it replaces the existing node
struct node* add(struct node* list, struct node* newNode) {
    // If the current node has the same key, then replace the value
    // with the new node's value
    if (strcmp(list->key, newNode->key) == 0) {
        list->value = newNode->value;
    } else if (list->next == NULL) {
        list->next = newNode;
    } else {
        add(list->next, newNode);
    }
    return list;
}

int find(struct node* list, char* key) {
    if (list == NULL) {
        return -1;
    }
    if (strcmp(list->key, key) == 0) {
        return list->value;
    }
    return find(list->next, key);
}

void printList(struct node* list) {
    if (list == NULL) {
        return;
    }
    printf(" %s:%i\n", list->key, list->value);
    printList(list->next);
}

/*
int main() {
    struct node* first = newNode(1, 10);
    struct node* second = newNode(2, 100);
    struct node* third = newNode(3, 1000);
    append(append(first, second), third);
    printList(first);
}
 */