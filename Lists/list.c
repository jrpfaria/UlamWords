#include "list.h"

void add(WordList* list, uint64_t value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void freeWordList(WordList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int found(uint64_t word, WordList* list) {
    Node* current = list->head;
    while (current != NULL)
    {
        if (current->value == word)
            return 1;
        current = current->next;
    }
    return 0;
}