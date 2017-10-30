//
// Created by Nicholas Yang on 10/30/17.
//

#ifndef DATASTRUCTURES_LINKED_LIST_H
#define DATASTRUCTURES_LINKED_LIST_H

struct node;
int find(struct node* list, char* key);
struct node* append(struct node* list, struct node* newNode);
struct node* add(struct node* list, struct node* newNode);
struct node* newNode(char* key, int value);
void printList(struct node* list);

#endif //DATASTRUCTURES_LINKED_LIST_H
