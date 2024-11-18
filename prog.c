#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define max_length 5
#define ones(x) ((1U << x) - 1)

typedef struct Node {
    struct Node* next;
    uint64_t value;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} WordList;

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
        {
            printf("Found %ld\n", word);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int is_ulam(uint64_t word, WordList* UlamWords, int l) {
    int num_reps = 0;
    uint64_t subword1, subword2;

    for (int i = 1; i < l; i++)
    {
        subword1 = word >> l-i;
        subword2 = word & ones(l-i);

        // maybe this is the problem
        if (subword1 != subword2 || i != l - i)
            if (found(subword1, &UlamWords[i-1]) && found(subword2, &UlamWords[l-i-1]))
                if (++num_reps > 1)
                    return 0;
        return num_reps;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    // Initialize UlamWords Lists
    WordList* UlamWords = malloc(max_length * sizeof(WordList));
    for (int i = 0; i < max_length; i++) {
        UlamWords[i].head = NULL;
        UlamWords[i].tail = NULL;
        UlamWords[i].size = 0;
    }

    // Add static values for lengths 1 and 2
    for (int i = 0; i < 2; i++)
        add(&UlamWords[0], i), add(&UlamWords[1], i+1);
    
    // Minor test
    printf("List 0 size: %d\n", UlamWords[0].size);
    printf("List 1 size: %d\n", UlamWords[1].size);

    // Generate Ulam Words
    for (int i = 2; i < max_length; i++) {
        // Otherwise this might be the problem
        for (int word = 0; word <= ones(i); word++) {
            printf("Testing Word: %d\n", word);
            if (is_ulam(word, UlamWords, i))
                add(&UlamWords[i], word), printf("Added %d\n", word);
        }
    }

    // Print Results
    FILE* fp = fopen("Words.txt", "w");
    for (int i = 0; i < max_length; i++)
        fprintf(fp, "Length %2d:\n%d\n", i+1, UlamWords[i].size);
    fclose(fp);

    // Helper print results
    FILE* fp2 = fopen("debug.txt", "w");
    for (int i = 0; i < max_length; i++) {
        fprintf(fp2, "Length %2d:\n", i+1);
        Node* current = UlamWords[i].head;
        while (current != NULL) {
            fprintf(fp2, "%ld\n", current->value);
            current = current->next;
        }
    }

    // Cleanup
    for (int i = 0; i < max_length; i++)
        freeWordList(&UlamWords[i]);
    free(UlamWords);

    return 0;
}
