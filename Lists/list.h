#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    struct Node* next;
    uint64_t value;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} WordList;

void add(WordList*, uint64_t);
void freeWordList(WordList*);
int found(uint64_t, WordList*);