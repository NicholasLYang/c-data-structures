//
// Created by Nicholas Yang on 10/30/17.
//
#include <stdio.h>
#include "linked_list.h"

int const ARRAY_SIZE = 100000;

struct node* buckets[ARRAY_SIZE];

int hash_key(char* key) {
    int hash = 5381;
    int c;
    while((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % ARRAY_SIZE;
}

void insert(char* key, int value) {
    int hashed_key = hash_key(key);
    struct node* node = newNode(key, value);
    if (buckets[hashed_key] == NULL) {
        buckets[hashed_key] = node;
        return;
    }
    add(buckets[hashed_key], node);
}

void printBucket(char* key) {
    int hashed_key = hash_key(key);
    printList(buckets[hashed_key]);
}


int get(char* key) {
    int hashed_key = hash_key(key);
    return find(buckets[hashed_key], key);
}

int main() {
    insert("Hello", 11);
    insert("World", 13);
    insert("Hello", 14);
    printBucket("Hello");
    printf("%i\n", get("Hello"));
    printf("%i\n", get("World"));
}
